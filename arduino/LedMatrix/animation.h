#include "frame.h"

#ifndef _ANIMATION_
#define _ANIMATION_

struct Animation {
  unsigned int frameCount;
  const Frame *frames;
};

typedef Animation Animation;

#endif
