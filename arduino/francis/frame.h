#ifndef _FRAME_
#define _FRAME_
struct Frame {
  unsigned long data[8];
  unsigned int frameTime;
};

typedef struct Frame Frame;
void frameFade(Frame * f);
#endif
