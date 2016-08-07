#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeJumpFrames[] PROGMEM = {

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
        0xF000000F,
        0xF00FF00F,
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

Animation eyeJump = {5, eyeJumpFrames};
