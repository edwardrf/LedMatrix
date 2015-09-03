#include "animation.h"
#include <avr/pgmspace.h>

const Frame arrowFrames[] PROGMEM = {
    {
      {
        0x0000FFFF,
        0x000FF0FF,
        0x00FF00FF,
        0x0FF000FF,
        0xFF0000FF,
        0xFFFFFFFF,
        0xFF0000FF,
        0xFF0000FF
      },
      1000
    }
  };

Animation arrow = {1, arrowFrames};
