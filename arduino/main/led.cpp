#include "led.h"

Animation * animation;
volatile unsigned int framePointer;
volatile unsigned char pwmCounter;
volatile unsigned char linePointer;
volatile bool repeat;
volatile bool running;
volatile unsigned long frameStartTime;
volatile unsigned char frameBuffer[15][8];

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

void initLed() {
  DDRD   = B11111111; // Whole port D is output
  PORTD  = B00000000; // Turn off all led HIGH side
  DDRB  |= B00000111; // PB0~PB2 controls the demultiplexer
  PORTB &= B11111000;
  pinMode(A3, OUTPUT);
  // digitalWrite(A3, HIGH);

  Timer1.initialize(100);
  Timer1.attachInterrupt(updateDisplay);
  Timer1.stop();
}

void setAnimation(Animation * a, bool loopAnimation) {
  animation = a;
  framePointer = 0;
  pwmCounter = 0;
  linePointer = 0;
  repeat = loopAnimation;
}

void startAnimation() {
  running = true;
  Timer1.start();
  digitalWrite(A3, HIGH);
  frameStartTime = millis();
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

void updateDisplay(){
  PORTD = 0; // Turn off display (high side);
  if(pwmCounter == 0 && linePointer == 0) {
    unsigned long t = millis();
    Timer1.stop();   // Stop the timer while prepare the frame
    if(running && t - frameStartTime > animation->getFrameTiming(framePointer)) {
      // Preapre the next frame
      framePointer ++;
      if(framePointer >= animation->getFrameCount()) {
        if(repeat == true) {
          framePointer = 0;
        }else {
          framePointer = animation->getFrameCount() - 1;
        }
      }
      _prepareFrame();
      frameStartTime = t;
    }
    Timer1.resume();
  }
  // Turn on a row of LED
  // Turn on the LOW side controlled by 74hc238, multplexer followd by darlingtons
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
}

void _prepareFrame() {
  Frame tmpf = animation->getFrame(framePointer);
  for(unsigned char i = 0; i < 15; i++) {
    unsigned long * data = tmpf.getData();
    for(unsigned char j = 0; j < 8; j++) {
      unsigned char b = 0;
      for(unsigned char k = 0; k < 8; k++) {
        b <<= 1;
        if(data[j] & masks[k]) b++;
      }
      frameBuffer[i][j] = b;
    }
    tmpf.fade();
  }
}
