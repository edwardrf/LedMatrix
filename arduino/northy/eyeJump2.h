#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeJump2Frames[] PROGMEM = {

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
        0x0F0000F0,
        0xF0FF000F,
        0xF0FF000F,
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
        0x0F0000F0,
        0xFFF0000F,
        0xFFF0000F,
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
        0x0F0000F0,
        0xF0000FFF,
        0xF0000FFF,
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

Animation eyeJump2 = {6, eyeJump2Frames};
