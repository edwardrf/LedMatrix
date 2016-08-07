#include "animation.h"
#include <avr/pgmspace.h>

const Frame arrowFrames[] PROGMEM = {
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
      100
    },
    
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
      100
    },
    
    {
      {
        0xFFFFFFFF,
        0x000FF0FF,
        0x00FFFFFF,
        0x0FF0FFFF,
        0xFF00FFFF,
        0xFFFFFFFF,
        0xFF0FF0FF,
        0xFF0000FF
      },
      100
    },
    
    {
      {
        0xFFF0000F,
        0x000FF0FF,
        0x00FF0000,
        0x0FF000FF,
        0xFF0000FF,
        0xFFFFFFFF,
        0xFF000000,
        0xFF0FF0FF
      },
      1000
    }
    
    
  };

Animation arrow = {4, arrowFrames};
