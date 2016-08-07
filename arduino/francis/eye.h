#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeFrames[] PROGMEM = {
    
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0xFFFFFFFF,
        0xF00FF00F,
        0x0F0000F0,
        0x00FFFF00,
        0x00000000
      },
      50
    },
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0xF000000F,
        0xFFFFFFFF,
        0x0F0000F0,
        0x00FFFF00,
        0x00000000
      },
      50
    },
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0xF000000F,
        0xFF0000FF,
        0x0FFFFFF0,
        0x00FFFF00,
        0x00000000
      },
      50
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
      50
    }
    
    
    
    
  };

Animation eye = {4, eyeFrames};
