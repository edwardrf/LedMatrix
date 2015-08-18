#include "animation.h"
#include <TimerOne.h>

void initLed();
void setAnimation(Animation * a, bool loopAnimation);
void startAnimation();
void stopAnimation();
void pauseAnimation();
void resumeAnimation();
void updateDisplay();
void _prepareFrame();
