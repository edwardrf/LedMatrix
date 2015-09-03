#include "animation.h"
#include "animations/wave.h"
#include "animations/white.h"
#include "animations/arrow.h"
#include "animations/fade.h"
#include "led.h"
#include <ADXL345.h>

#define SOUND_IN A7
#define LIGHT_IN A6

ADXL345 accel;

Animation animations[] = {wave, white, arrow, fade};
bool hasAccel = false;
enum Mode {
  NOTHING,
  NORMAL,
  SOUND_INT,
  LIGHT_INT
};

Mode toMode, currentMode;

void setup(){
  // Initialize LED display
  initLed();
  toMode = NORMAL;
  // setAnimation(&animations[3], true);
  startAnimation();

  // Initialize accelerometer
  TWBR = ((F_CPU / 400000) - 16) / 2; // faster 400khz I2C, rather than the default 100khz
  Wire.begin();
  accel.initialize();
  accel.setOffset(-54, -38, -47);

  // Test if accelerometer is working correctly
  hasAccel = accel.testConnection();
  if(!hasAccel) {
    setAnimation(&animations[1], true); // Display a error message animation
  }

  // Initialize the microphone
  pinMode(11, OUTPUT);
  // Set up the 2Mhz output
  // WGM2 [2:0] = 111 ==> fast PWM
  // COM2A[1:0] =  01 ==> toggle OC2A when reach OCR2A
  // OCR2A      =   1 ==> count 2 number before toggle (0, 1), thus giving a frequency of 8Mhz / 2 / 2 = 2Mhz
  TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = 1;

  // Serial.begin(115200);
}

unsigned long lastAccCheck = 0;
unsigned long intStart = 0;
double soundLevel = 0;

void loop(){
  // Update to next frame when necessary, this has to be called
  // in the main frame as running it in the interrup routine would cause flicker
  // in the animation
  updateFrame();

  // Check accelerometer
  unsigned long t = millis();
  if(lastAccCheck - t > 100) {
    int16_t ax, ay, az, mx, my;
    Orientation o;
    accel.getAcceleration(&ax, &ay, &az);
    // Deduce orientation, we only care about x and y orientation
    mx = ax > 0 ? ax : -ax;
    my = ay > 0 ? ay : -ay;
    if(my >= mx) {
      if(ay > 0) o = ORI_DOWN; else o = ORI_UP;
    }else {
      if(ax > 0) o = ORI_RIGHT; else o = ORI_LEFT;
    }
    setOrientation(o);

    // Serial.print("accel:\t");
    // Serial.print(ax); Serial.print("\t");
    // Serial.print(ay); Serial.print("\t");
    // Serial.print(az); Serial.print("\t");
    // Serial.println(o);
    // if(o == ORI_LEFT) {
    //   setAnimation(&animations[0], true);
    // }
    lastAccCheck = t;
  }

  // Check Sound
  int snd = analogRead(SOUND_IN);
  // soundLevel = soundLevel *
  // snd = snd > 338 ? snd - 338 : 338 - snd;
  int diff = snd > soundLevel ? snd - soundLevel : soundLevel - snd;
  if(currentMode == NORMAL && diff > 12) {
    // Serial.print("Sound "); Serial.print(snd);
    // Sound wake up code here
    // Serial.print("\t"); Serial.println(soundLevel);
    toMode = SOUND_INT;
    // setAnimation(&animations[2], true);
  }
  soundLevel = (soundLevel * 90 + snd * 10) / 100;

  // Check Light
  int lit = analogRead(LIGHT_IN);
  if(lit > 500) {
    // Light wake up code here
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
      setAnimation(&animations[0], true);
      break;
    case SOUND_INT:
      setAnimation(&animations[2], true);
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
