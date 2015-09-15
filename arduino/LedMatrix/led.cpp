#include "led.h"

Animation * animation;
Frame currentFrame;
volatile unsigned int framePointer;
volatile unsigned char pwmCounter;
volatile unsigned char linePointer;
volatile bool repeat;
volatile bool running;
volatile unsigned long frameStartTime;
volatile unsigned char frameBuffer[15][8];
volatile uint8_t brightness = 8, bCnt = 0;
volatile Orientation orientation;

// Somehow arduino make file duplicates definiation when this is placed in .h file
unsigned long masks[8] = {
  0xF0000000,
  0x0F000000,
  0x00F00000,
  0x000F0000,
  0x0000F000,
  0x00000F00,
  0x000000F0,
  0x0000000F
};

void setOrientation(Orientation o) {
  orientation = o;
}

void setBrightness(uint8_t b) {
  brightness = b;
  if(brightness > 8) brightness = 8;
}

void initLed() {
  DDRD   = B11111111; // Whole port D is output
  PORTD  = B00000000; // Turn off all led HIGH side
  DDRB  |= B00000111; // PB0~PB2 controls the demultiplexer
  PORTB &= B11111000;
  pinMode(A3, OUTPUT);
  // digitalWrite(A3, HIGH);

  Timer1.initialize(15);
  Timer1.attachInterrupt(updateDisplay);
  Timer1.stop();
}

void setAnimation(Animation * a, bool loopAnimation) {
  animation = a;
  framePointer = 0;
  pwmCounter = 0;
  linePointer = 0;
  memcpy_P(&currentFrame, &(animation->frames[framePointer]), sizeof(Frame));
  _prepareFrame();
  repeat = loopAnimation;
}

void startAnimation() {
  running = true;
  Timer1.start();
  digitalWrite(A3, HIGH);
  frameStartTime = millis();
  bCnt = 0;
}

void stopAnimation() {
  running = false;
  Timer1.stop();
  PORTD = 0;
  digitalWrite(A3, LOW);
}

void pauseAnimation() {
  running = false;
}

void resumeAnimation() {
  running = true;
}

void updateFrame() {
  unsigned long t = millis();
  if(running && t - frameStartTime > currentFrame.frameTime) {
    // Preapre the next frame
    framePointer ++;
    if(framePointer >= animation->frameCount) {
      if(repeat == true) {
        framePointer = 0;
      }else {
        framePointer = animation->frameCount - 1;
      }
    }
    memcpy_P(&currentFrame, &(animation->frames[framePointer]), sizeof(Frame));
    _prepareFrame();
    frameStartTime = t;
  }
}

void updateDisplay(){
  if(bCnt == 0){
    // Turn on a row of LED
    // Turn on the LOW side controlled by 74hc238, multplexer followd by darlingtons
    PORTD = 0;
    PORTB &= B11111000;   // Clear
    PORTB |= linePointer; // Then set
    // Turn on the HIGH side through PORTD
    PORTD = frameBuffer[pwmCounter][linePointer];

    // Advance to next line
    linePointer ++;
    if(linePointer >= 8) {
      linePointer = 0;
      pwmCounter ++;
      if(pwmCounter >= 15) {
        pwmCounter = 0;
      }
    }
  }else if(bCnt > brightness) {
    PORTD = 0;
  }
  if(bCnt++ > 8) bCnt = 0;
}

void _prepareFrame() {
  Frame tmpf = currentFrame;

  switch(orientation) {
  case ORI_UP:
    for(unsigned char i = 0; i < 15; i++) {
      for(unsigned char j = 0; j < 8; j++) {
        unsigned char b = 0;
        for(unsigned char k = 0; k < 8; k++) {
          b <<= 1;
          if(tmpf.data[j] & masks[7-k]) b++;
        }
        frameBuffer[i][7-j] = b;
      }
      frameFade(&tmpf);
    }
    break;
  case ORI_DOWN:
    for(unsigned char i = 0; i < 15; i++) {
      for(unsigned char j = 0; j < 8; j++) {
        unsigned char b = 0;
        for(unsigned char k = 0; k < 8; k++) {
          b <<= 1;
          if(tmpf.data[7-j] & masks[k]) b++;
        }
        frameBuffer[i][7-j] = b;
      }
      frameFade(&tmpf);
    }
    break;
  case ORI_LEFT:
    for(unsigned char i = 0; i < 15; i++) {
      for(unsigned char j = 0; j < 8; j++) {
        unsigned char b = 0;
        for(unsigned char k = 0; k < 8; k++) {
          b <<= 1;
          if(tmpf.data[k] & masks[j]) b++;
        }
        frameBuffer[i][7-j] = b;
      }
      frameFade(&tmpf);
    }
    break;
  case ORI_RIGHT:
    for(unsigned char i = 0; i < 15; i++) {
      for(unsigned char j = 0; j < 8; j++) {
        unsigned char b = 0;
        for(unsigned char k = 0; k < 8; k++) {
          b <<= 1;
          if(tmpf.data[7-k] & masks[7-j]) b++;
        }
        frameBuffer[i][7-j] = b;
      }
      frameFade(&tmpf);
    }
    break;
  }
}
