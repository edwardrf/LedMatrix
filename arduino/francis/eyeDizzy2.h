#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeDizzy2Frames[] PROGMEM = {
  
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
    },
    
    {
      {
        0x00000000,
        0x00FFFF00,
        0x0F0000F0,
        0xF000000F,
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
        0x0FF00FF0,
        0xFF0000FF,
        0xFF0000FF,
        0x0FF00FF0,
        0x00FFFF00,
        0x00000000
      },
      50
    },
    
    {
      {
        0x00000000,
        0x00FFFF00,
        0x0FFFFFF0,
        0xFFF00FFF,
        0xFFF00FFF,
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
        0x0F0FF0F0,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0x0F0FF0F0,
        0x00FFFF00,
        0x00000000
      },
      50
    }
    
    
    
  };

Animation eyeDizzy2 = {5, eyeDizzy2Frames};
