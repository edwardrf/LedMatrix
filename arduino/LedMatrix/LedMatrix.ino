#include "animation.h"
#include "wave.h"
#include "white.h"
#include "arrow.h"
#include "fade.h"
#include "heart.h"
#include "led.h"
#include <ADXL345.h>
#include <APDS9900.h>
#include <EEPROM.h>

#define SOUND_IN A7

ADXL345 accel;
APDS9900 apds;

Animation animations[] = {wave, white, arrow, fade, heart};
bool hasAccel = false;
enum Mode {
  NOTHING,
  NORMAL,
  SOUND_INT,
  LIGHT_INT
};

Mode toMode, currentMode;
double normalSpeed = 1.0, speed = 1.0;

void setup(){
  // Initialize LED display
  initLed();
  toMode = NORMAL;
  // setAnimation(&animations[3], true);
  startAnimation();
  setBrightness(1);
  // setSpeed(0.8);
  // Initialize accelerometer
  TWBR = ((F_CPU / 400000) - 16) / 2; // faster 400khz I2C, rather than the default 100khz
  Wire.begin();
  accel.initialize();

  // ==== NEW CODE ===
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
    setAnimation(&animations[1], true); // Display a error message animation
  }

  // Initialize the microphone
  // pinMode(11, OUTPUT);
  // Set up the 2Mhz output
  // WGM2 [2:0] = 111 ==> fast PWM
  // COM2A[1:0] =  01 ==> toggle OC2A when reach OCR2A
  // OCR2A      =   1 ==> count 2 number before toggle (0, 1), thus giving a frequency of 8Mhz / 2 / 2 = 2Mhz
  // TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM20);
  // TCCR2B = _BV(WGM22) | _BV(CS20);
  // OCR2A = 1;

  // Serial.begin(115200);
  // Serial.println("Starting");
}

unsigned long lastAccCheck = 0;
unsigned long intStart = 0;
double soundLevel = 0;
unsigned int lightLevel = 0;
bool lightChecked = 0;

void loop(){
  // Update to next frame when necessary, this has to be called
  // in the main frame as running it in the interrup routine would cause flicker
  // in the animation
  updateFrame();

  // Check Sound
  int snd = analogRead(SOUND_IN);
  int sndDiff = snd > soundLevel ? snd - soundLevel : soundLevel - snd;
  if(sndDiff > 30){
    speed = 0.2; // Faster beat
  }
  soundLevel = (soundLevel * 90 + snd * 10) / 100;

  // Check Light
  // int lit = analogRead(LIGHT_IN);
  // if(lit < 500) {
  //   normalSpeed = 1.5;
  // }else {
  //   normalSpeed = 1.0;
  // }

  // Check accelerometer and light using 12c
  unsigned long t = millis();
  if(lastAccCheck - t > 200) {

    if(lightChecked) {
      lightLevel = apds.getLux();
      // Serial.println(lightLevel);
      lightChecked = false;
    }else {
      apds.initialize();
      lightChecked = true;
    }

    int16_t ax, ay, az, mx, my;
    Orientation o;
    accel.getAcceleration(&ax, &ay, &az);
    // Deduce orientation, we only care about x and y orientation
    mx = ax > 0 ? ax : -ax;
    my = ay > 0 ? ay : -ay;
    // ==== NEW CODE ===
    int diff = my > mx ? my - mx : mx - my;
    if(diff > 150) {
      if(my >= mx) {
        if(ay > 0) o = ORI_DOWN; else o = ORI_UP;
      }else {
        if(ax > 0) o = ORI_RIGHT; else o = ORI_LEFT;
      }
      setOrientation(o);
    }

    speed = (speed * 99 + normalSpeed) / 100;
    setSpeed(speed);
    // Serial.println(speed);

    lastAccCheck = t;
  }



  // Return to normal mode after 2 seconds of interruption
  if(currentMode != NORMAL && t - intStart > 2000) {
    // Serial.println("back to normal");
    toMode = NORMAL;
  }

  // Choose the animation based on the mode
  if(toMode != currentMode) {
    // Serial.print("================Switch to mode "); Serial.print(toMode); Serial.print("\t"); Serial.println(intStart);
    switch(toMode) {
    case NORMAL:
      setAnimation(&animations[4], true);
      break;
    case SOUND_INT:
      setAnimation(&animations[2], true);
      // setAnimation(&animations[2], true);
      break;
    case LIGHT_INT:
      setAnimation(&animations[0], true);
      break;
    default:
      setAnimation(&animations[0], true);
      break;
    }
    currentMode = toMode;
    intStart = t;
  }

}
