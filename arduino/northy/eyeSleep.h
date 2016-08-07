#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeSleepFrames[] PROGMEM = {
    
    
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
      500
    },
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0xF000000F,
        0xF000000F,
        0x0F0000F0,
        0x00FFFF00,
        0x00000000
      },
      500
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
      200
    }
    

    
    
    
    
  };

Animation eyeSleep = {3, eyeSleepFrames};
