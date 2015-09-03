#ifndef _FRAME_
#define _FRAME_
class Frame {
  unsigned long data[8];

public:
  Frame(unsigned long d[]){setData(d);};
  Frame(unsigned long d0, unsigned long d1, unsigned long d2, unsigned long d3, unsigned long d4, unsigned long d5, unsigned long d6, unsigned long d7) {
    data[0] = d0;
    data[1] = d1;
    data[2] = d2;
    data[3] = d3;
    data[4] = d4;
    data[5] = d5;
    data[6] = d6;
    data[7] = d7;
  }
  void fade();
  inline unsigned long * getData() {
    return data;
  }

  inline void setData(unsigned long d[]) {
    for(unsigned char i = 0; i < 8; i++) {
      data[i] = d[i];
    }
  }

};
#endif
