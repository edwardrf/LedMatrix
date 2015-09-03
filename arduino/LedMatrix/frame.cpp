#include "frame.h"

void frameFade(Frame* f){
  for(unsigned char i = 0; i < 8; i++) {
    if(f->data[i] & 0xF0000000) f->data[i] -= 0x10000000;
    if(f->data[i] & 0x0F000000) f->data[i] -= 0x01000000;
    if(f->data[i] & 0x00F00000) f->data[i] -= 0x00100000;
    if(f->data[i] & 0x000F0000) f->data[i] -= 0x00010000;
    if(f->data[i] & 0x0000F000) f->data[i] -= 0x00001000;
    if(f->data[i] & 0x00000F00) f->data[i] -= 0x00000100;
    if(f->data[i] & 0x000000F0) f->data[i] -= 0x00000010;
    if(f->data[i] & 0x0000000F) f->data[i] -= 0x00000001;
  }
}
