#include "frame.h"

void Frame::fade(){
  for(unsigned char i = 0; i < 8; i++) {
    if(data[i] & 0xF0000000) data[i] -= 0x10000000;
    if(data[i] & 0x0F000000) data[i] -= 0x01000000;
    if(data[i] & 0x00F00000) data[i] -= 0x00100000;
    if(data[i] & 0x000F0000) data[i] -= 0x00010000;
    if(data[i] & 0x0000F000) data[i] -= 0x00001000;
    if(data[i] & 0x00000F00) data[i] -= 0x00000100;
    if(data[i] & 0x000000F0) data[i] -= 0x00000010;
    if(data[i] & 0x0000000F) data[i] -= 0x00000001;
  }
}
