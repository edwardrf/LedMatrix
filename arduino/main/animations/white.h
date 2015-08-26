#include "../animation.h"

unsigned int whiteTiming[] = {200};
Frame whiteFrames[]= {
    Frame(
      0xFFFFFFFF,
      0xFFFFFFFF,
      0xFFFFFFFF,
      0xFFFFFFFF,
      0xFFFFFFFF,
      0xFFFFFFFF,
      0xFFFFFFFF,
      0xFFFFFFFF
    )
  };

Animation white(1, whiteTiming, whiteFrames);
