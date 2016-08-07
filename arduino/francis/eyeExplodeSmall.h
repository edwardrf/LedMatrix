#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeExplodeSmallFrames[] PROGMEM = {

   {
      {
        0x00000000,
        0x00FFFF00,
        0x0F0000F0,
        0xF00FF00F,
        0xF00FF00F,
        0x0F0000F0,
        0x00FFFF00,
        0x00000000
      },
      40
    },
    
     {
      {
        0x00000000,
        0x00FFFF00,
        0x0F0FF0F0,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0x0F0FF0F0,
        0x00FFFF00,
        0x00000000
      },
      40
    },
    
    {
      {
        0x00000000,
        0x00FFFF00,
        0x0FFFFFF0,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0x0FFFFFF0,
        0x00FFFF00,
        0x00000000
      },
      100
    },
    
     {
      {
        0x00000000,
        0x00FFFF00,
        0x0F0FF0F0,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0x0F0FF0F0,
        0x00FFFF00,
        0x00000000
      },
      40
    },
    
    {
   {
        0x00000000,
        0x00FFFF00,
        0x0F0000F0,
        0xF00FF00F,
        0xF00FF00F,
        0x0F0000F0,
        0x00FFFF00,
        0x00000000
      },
      40
    }
    
    
  
    
    
    
};

Animation eyeExplodeSmall = {5, eyeExplodeSmallFrames};
