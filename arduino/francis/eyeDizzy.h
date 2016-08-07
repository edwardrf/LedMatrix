#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeDizzyFrames[] PROGMEM = {
  
    {
      {
        0x00000000,
        0x00FFFF00,
        0x0F0000F0,
        0xFFF0000F,
        0xFFF0000F,
        0x0F0000F0,
        0x00FFFF00,
        0x00000000
      },
      50
    },
    
    {
      {
        0x00000000,
        0x00FFFF00,
        0x0F0FF0F0,
        0xF00FF00F,
        0xF000000F,
        0x0F0000F0,
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
        0xF0000FFF,
        0xF0000FFF,
        0x0F0000F0,
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
        0xF000000F,
        0xF00FF00F,
        0x0F0FF0F0,
        0x00FFFF00,
        0x00000000
      },
      50
    }
    
    
  };

Animation eyeDizzy = {4, eyeDizzyFrames};
