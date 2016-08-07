#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeSuperBrightFrames[] PROGMEM = {
    
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0xFFFFFFFF,
        0x00000000,
        0x00000000,
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
        0x0FFFFFF0,
        0x00000000,
        0x00000000,
        0x00000000
      },
      50
    }
    

    
    
    
    
  };

Animation eyeSuperBright = {2, eyeSuperBrightFrames};
