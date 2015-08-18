#include "animation.h"
#include "animations/wave.h"
#include "animations/white.h"
#include "led.h"

Animation animations[] = {wave, white};

void setup(){
  initLed();
  setAnimation(&animations[0], true);
  startAnimation();
  // DDRD  = B11111111;
  // PORTD = B10000000;
  // DDRB |= B00000111; // PB0~PB2 controls the demultiplexer
  //
  // pinMode(13, OUTPUT);
  // pinMode(0, OUTPUT);
  // pinMode(1, OUTPUT);
  // pinMode(2, OUTPUT);
  // pinMode(3, OUTPUT);
  // pinMode(4, OUTPUT);
  // pinMode(5, OUTPUT);
  // pinMode(6, OUTPUT);
  // pinMode(7, OUTPUT);
  // pinMode(8, OUTPUT);
  // pinMode(9, OUTPUT);
  // pinMode(10, OUTPUT);
  // pinMode(A3, OUTPUT);
  //
  // digitalWrite(A3, HIGH);
  // digitalWrite(0, HIGH);
  // digitalWrite(1, LOW);
  // digitalWrite(2, LOW);
  // digitalWrite(3, LOW);
  // digitalWrite(4, LOW);
  // digitalWrite(5, LOW);
  // digitalWrite(6, LOW);
  // digitalWrite(7, HIGH);
  // digitalWrite(8, LOW);
  // digitalWrite(9, LOW);
  // digitalWrite(10, HIGH);
}

// uint8_t v = 0;
void loop(){
  // digitalWrite(7, HIGH);
  // delay(100);
  // digitalWrite(7, LOW);
  // delay(100);
  // PORTB &= B00011111; // Clear the output value
  // PORTB |= v++;       // Output to demutiplexer
  // delay(1000);
  // if(v >= 15) v = 0;
}
