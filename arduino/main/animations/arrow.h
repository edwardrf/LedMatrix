#include "../animation.h"

unsigned int arrowTiming[] = {200};
Frame arrowFrames[]= {
    Frame(
      0x0000FFFF,
      0x000FF0FF,
      0x00FF00FF,
      0x0FF000FF,
      0xFF0000FF,
      0xFFFFFFFF,
      0xFF0000FF,
      0xFF0000FF
    )
  };

Animation arrow(1, arrowTiming, arrowFrames);
