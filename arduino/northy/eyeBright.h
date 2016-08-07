#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeBrightFrames[] PROGMEM = {
    

    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0xFFFFFFFF,
        0xF00FF00F,
        0x0FFFFFF0,
        0x00000000,
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
        0x0FFFFFF0,
        0x00000000,
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
        0xF000000F,
        0x0FFFFFF0,
        0x00000000,
        0x00000000
      },
      50
    },
    
     {
      {
        0x00000000,
        0x00000000,
        0x0FFFFFF0,
        0xF00FF00F,
        0xF00FF00F,
        0x0FFFFFF0,
        0x00000000,
        0x00000000
      },
      50
    }
    
    

    
    
    
    
  };

Animation eyeBright = {4, eyeBrightFrames};
