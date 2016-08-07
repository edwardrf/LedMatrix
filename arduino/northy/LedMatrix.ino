#include "animation.h"
#include <TimerOne.h>
#include "wave.h"
#include "white.h"
#include "northy.h"
#include "eye.h"
#include "eyeMove.h"
#include "eyeSleep.h"
#include "eyeBright.h"
#include "eyeExplode.h"
#include "eyeExplodeSmall.h"
#include "eyeDizzy.h"
#include "eyeDizzy2.h"
#include "eyeStare.h"
#include "eyeRoll.h"
#include "eyeJump.h"
#include "eyeJump2.h"
#include "eyeSuperBright.h"
#include "fade.h"
#include "led.h"
#include <I2Cdev.h>
#include <ADXL345.h>
#include <AP3216C.h>
#include <Wire.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>


#define SOUND_IN A7
#define LIGHT_IN A6

#define SLEEP_LIT 100
#define SOUND_THRES 10 // 0->most sensitive
#define BACK_TO_NORMAL_TIME 2000 //ms
#define WAKE_TIME 5000 //ms
#define SHAKE_THRES 15 * 15 //shake value, compare the square sum of 3 axis //150
#define LED_BRIGHTNESS 8 //default brightness 1-8, 8=brightness, 1=dimmest (for product version)

ADXL345 accel;
AP3216C als;
SoftwareSerial comm(12, 11, 1); // Inverse logic as LOW on 12 is indicating master

enum AniName {
  ANI_WAVE,
  ANI_WHITE,
  ANI_FADE,
  ANI_NORTHY,
  ANI_EYE,
  ANI_EYE_MOVE,
  ANI_EYE_SLEEP,
  ANI_EYE_SUPER_BRIGHT,
  ANI_EYE_BRIGHT,
  ANI_EYE_EXPLODE,
  ANI_EYE_DIZZY,
  ANI_EYE_DIZZY2,
  ANI_EYE_STARE,
  ANI_EYE_EXPLODE_SMALL,
  ANI_EYE_ROLL,
  ANI_EYE_JUMP,
  ANI_EYE_JUMP2
};

Animation animations[] = {wave, white, fade, northy, eye, eyeMove, eyeSleep, eyeSuperBright, eyeBright, eyeExplode,eyeDizzy,eyeDizzy2,eyeStare,eyeExplodeSmall,eyeRoll,eyeJump,eyeJump2};
bool hasAccel = false;
enum Mode {
  NOTHING,
  NORMAL,
  SOUND_XL,
  SOUND_L,
  SOUND_M,
  SOUND_S,
  SOUND_XS,
  LIGHT_0,
  LIGHT_1,
  LIGHT_2,
  LIGHT_3,
  LIGHT_4,
  SHAKE_L,
  SHAKE_M,
  SHAKE_S
};

unsigned int wakeTime;

volatile Mode toMode, currentMode;

unsigned long lastAccCheck = 0;
unsigned long lastLightCheck = 0;
unsigned long soundMotionStart = 0;
unsigned long backToNormalTime = 0;
unsigned long noInterruptTime = 0;
double soundLevel = 0;
int16_t lastX,lastY,lastZ, shakeVal;
bool isSlave = false;

void setup(){
  // Determine Master slave relationship
  pinMode(11, OUTPUT);    // Fisrt set MOSI to high
  digitalWrite(11, LOW);
  // Then read MISO to determine if it is connected as slave
  pinMode(12, INPUT);
  digitalWrite(12, HIGH); // Use the interal pull up to avoid floating reading
  delay(250);              // A brief delay to ensure the master is ready
  for(uint8_t i = 0; i < 50; i++) { // Multiple sampling to prevent false reading when master is transfering
    if(digitalRead(12) == LOW) isSlave = true;
    delay(10);
  }

  // Initialize LED display
  setBrightness(LED_BRIGHTNESS);  ////1-8 8:brightest
  initLed();
  currentMode = toMode = NORMAL;
  startAnimation();

  // Initialize I2C devices
  TWBR = ((F_CPU / 400000) - 16) / 2; // faster 400khz I2C, rather than the default 100khz
  Wire.begin();
  accel.initialize(); // Initialize the accelerameter
  als.initialize();   // Initialize the ambient light sensor
  als.setAlsGain(3);  // set gain of the light sensor, 0~3, 3 being most sensitive

  // Retrive previous calibration value if exists
  int8_t calibrated = EEPROM.read(0);
  int8_t xoffset = 0;
  int8_t yoffset = 0;
  int8_t zoffset = 0;
  if(calibrated == 0xCA){
    xoffset = EEPROM.read(1);
    yoffset = EEPROM.read(2);
    zoffset = EEPROM.read(3);
    accel.setOffset(xoffset, yoffset, zoffset);
  }

  // Test if accelerometer is working correctly
  hasAccel = accel.testConnection();
  if(!hasAccel) {
    setAnimation(&animations[ANI_WHITE], 0); // Display a error message animation
  }
  
  // init random values
  wakeTime=WAKE_TIME+random(WAKE_TIME);

  comm.begin(57600);
}

void loop(){
  // Update to next frame when necessary, this has to be called
  // in the main frame as running it in the interrup routine would cause flicker
  // in the animation
  updateFrame();

  // Check accelerometer --------------------------------------------------------
  unsigned long t = millis();

  if(isSlave) {
    if(comm.available() > 0) {
      toMode = (Mode) comm.read();
      comm.write(toMode);
    }
  } else { 
    // Check accelerameter
    if(t - lastAccCheck > 100) {
      int16_t ax, ay, az, dx, dy, dz;
      accel.getAcceleration(&ax, &ay, &az);
  
      // Check for shakes
      dx = (lastX - ax) / 10;
      dy = (lastY - ay) / 10;
      dz = (lastZ - az) / 10;
      int dd = dx * dx + dy * dy + dz * dz;
      if(dd > SHAKE_THRES * 3) {
        toMode = SHAKE_L;
      } else if(dd > SHAKE_THRES * 2) {
        toMode = SHAKE_M;
      } else if(dd > SHAKE_THRES) {
        toMode = SHAKE_S;
      }
      
      lastX=ax;
      lastY=ay;
      lastZ=az;
      
      lastAccCheck = t;
    }
  
    
    // Check Sound  --------------------------------------------------------
    int snd = analogRead(SOUND_IN);
    int diff=snd-soundLevel;
    if(diff>SOUND_THRES*2.5) { 
      toMode = SOUND_XL;
    } else if(diff>SOUND_THRES*1.9) { 
      toMode = SOUND_L;
    } else if(diff>SOUND_THRES*1.6) {
      toMode = SOUND_M;
    } else if(diff>SOUND_THRES*1.3) {
      toMode = SOUND_S;
    } else if(diff>SOUND_THRES) {
      toMode = SOUND_XS;
    }
    soundLevel = (soundLevel * 90 + snd * 10) / 100; // Low pass filter to keep track of normal sound level
  
    // Check Light  --------------------------------------------------------
    if(t > backToNormalTime && t-lastLightCheck> 500) {
      int lit = als.getAmbientLight();
      
      if(lit<SLEEP_LIT && t-soundMotionStart< wakeTime) {
        if(t-soundMotionStart<wakeTime/2) {
          lit+=SLEEP_LIT*3;
        } else {
          lit+=SLEEP_LIT; //force wait up
        }
      }  
      
      if(lit>700) {
        toMode=LIGHT_0;
      } else if(lit>500) {
        toMode=LIGHT_1;
      } else if(lit>300) {
        toMode=LIGHT_2;
      } else if(lit>SLEEP_LIT) {
        toMode=LIGHT_3;
      } else {
        toMode=LIGHT_4;  //darkest
      }
      
      lastLightCheck=t;
    }
    if(t < noInterruptTime) return; // Do not check anything in no interrupt mode
  }
  
  // Choose the animation based on the mode
  if(toMode != currentMode) {
    switch(toMode) {
    case LIGHT_0:
      setAnimation(&animations[ANI_EYE_SUPER_BRIGHT], 30);
      break;
    case LIGHT_1:
      setAnimation(&animations[ANI_EYE_BRIGHT], 50);
      break;
    case LIGHT_3:
      setAnimation(&animations[ANI_EYE_MOVE], 50);
      break;
    case LIGHT_4:
      setAnimation(&animations[ANI_NORTHY], 0);
      // setAnimation(&animations[ANI_EYE_SLEEP], 50);
      break;
    case SOUND_XL:
      setAnimation(&animations[ANI_EYE_EXPLODE], -1);
      backToNormalTime = t + 2500;
      noInterruptTime = t + 2500;
      break;
    case SOUND_L:
      setAnimation(&animations[ANI_EYE_EXPLODE], -1);
      backToNormalTime = t + 2500;
      break;
    case SOUND_M:
      setAnimation(&animations[ANI_EYE_EXPLODE_SMALL], -1);
      backToNormalTime = t + 2500;
      break;
    case SOUND_S:
      setAnimation(&animations[ANI_EYE_ROLL], -1);
      backToNormalTime = t + 2500;
      break;
    case SOUND_XS:
      setAnimation(&animations[ANI_EYE_JUMP], -1);
      backToNormalTime = t + 2500;
      break;
    case SHAKE_L:
      setAnimation(&animations[ANI_EYE_DIZZY2], 0);
      backToNormalTime = t + 2500;
      break;
    case SHAKE_M:
      setAnimation(&animations[ANI_EYE_DIZZY], 0);
      backToNormalTime = t + 2500;
      break;
    case SHAKE_S:
      setAnimation(&animations[ANI_EYE_STARE], 0);
      backToNormalTime = t + 2500;
      break;
    default:
      setAnimation(&animations[ANI_EYE], 80);
      break;
    }
    currentMode = toMode;
    
    if(!isSlave) {
      comm.write(currentMode);
    }
  }

}
