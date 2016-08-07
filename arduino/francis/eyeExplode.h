#include "animation.h"
#include <avr/pgmspace.h>

const Frame eyeExplodeFrames[] PROGMEM = {

    {
      {
        0x00FFFF00,
        0x0F0000F0,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0x0F0000F0,
        0x00FFFF00
      },
      20
    },
    
    {
      {
        0x00FFFF00,
        0x0F0000F0,
        0xF00FF00F,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0xF00FF00F,
        0x0F0000F0,
        0x00FFFF00
      },
      20
    },
    
    {
      {
        0x00FFFF00,
        0x0F0000F0,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0xF0FFFF0F,
        0x0F0000F0,
        0x00FFFF00
      },
      20
    },
    
    {
      {
        0x00FFFF00,
        0x0F0FF0F0,
        0xF0FFFF0F,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xF0FFFF0F,
        0x0F0FF0F0,
        0x00FFFF00
      },
      20
    },
    
    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF00FFFFF,
        0xF000000F,
        0xF00FFFFF,
        0xF00FFFFF,
        0xFFFFFFFF
      },
      800
    },
    
    {
      {
        0xFFFFFFFF,
        0xF00FFFFF,
        0xF00FFFFF,
        0xF00FFFFF,
        0xF00FFFFF,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      800
    },
    
    {
      {
        0x00000000,
        0x00DDDD00,
        0x0DDDDDD0,
        0xDDDDDDDD,
        0xDDDDDDDD,
        0x0DDDDDD0,
        0x00DDDD00,
        0x00000000
      },
      100
    },
    
    {
      {
        0x00000000,
        0x00000000,
        0x00099000,
        0x00999900,
        0x00999900,
        0x00099000,
        0x00000000,
        0x00000000
      },
      100
    },
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00077000,
        0x00077000,
        0x00000000,
        0x00000000,
        0x00000000
      },
      100
    },
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000
      },
      100
    }, 
    
    
    
    {
      {
        0x00000000,
        0x00000000,
        0x00000000,
        0x90000009,
        0x90000009,
        0x09000090,
        0x00999900,
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
      40
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

Animation eyeExplode = {14, eyeExplodeFrames};
