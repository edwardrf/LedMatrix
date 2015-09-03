#include "animation.h"
#include "animations/wave.h"
#include <cstdio>
#include <iostream>

using namespace std;

#define B2BP "%d%d%d%d%d%d%d%d"
#define B2B(byte) (byte & 0x80 ? 1 : 0),(byte & 0x40 ? 1 : 0),(byte & 0x20 ? 1 : 0),(byte & 0x10 ? 1 : 0),(byte & 0x08 ? 1 : 0),(byte & 0x04 ? 1 : 0),(byte & 0x02 ? 1 : 0),(byte & 0x01 ? 1 : 0)

volatile unsigned char frameBuffer[16][8];
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

Animation animation = wave;

void _prepareFrame();

int main() {
  printf("Hello World!\n");
  _prepareFrame();
  for(int j = 0; j < 16; j++) {
    for(int i = 0; i < 8; i++) {
      printf (" ["B2BP"]\n", B2B(frameBuffer[j][i]));
    }
    printf("==============\n");
  }
}

void _prepareFrame() {
  Frame tmpf = animation.getFrame(7);
  for(unsigned char i = 0; i < 15; i++) {
    unsigned long * data = tmpf.getData();
    for(unsigned char j = 0; j < 8; j++) {
      unsigned char b = 0;
      for(unsigned char k = 0; k < 8; k++) {
        b = b << 1;
        if(data[j] & masks[k]) b++;
      }
      frameBuffer[i][j] = b;
      printf (" [%lX]\n", data[j]);
    }
    tmpf.fade();
  }
}
