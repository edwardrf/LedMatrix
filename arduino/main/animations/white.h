#include "../animation.h"
#include <avr/pgmspace.h>

const Frame whiteFrames[] PROGMEM = {
    {
      {
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF,
        0xFFFFFFFF
      },
      1000
    }
  };

Animation white = {1, whiteFrames};
