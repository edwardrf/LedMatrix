#include "frame.h"

#ifndef _ANIMATION_
#define _ANIMATION_
class Animation {
  unsigned int frameCount;
  unsigned int *frameTiming;
  Frame *frames;

public:

  Animation(unsigned int kfc, unsigned int * kft, Frame * fs): frameCount(kfc), frameTiming(kft), frames(fs) {};
  Frame getFrame(unsigned int frameNumber) {return frames[frameNumber];};
  inline unsigned int getFrameCount() {return frameCount;};
  inline unsigned int getFrameTiming(unsigned int frameNumber) {return frameTiming[frameNumber];};
};

#endif
