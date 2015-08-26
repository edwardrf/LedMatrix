#include "../animation.h"

unsigned int fadeTiming[] = {
  300, 300, 300, 300, 300, 300, 300, 300,
  300, 300, 300, 300, 300, 300, 300, 300
  // 100, 100, 100, 100, 100, 100, 100, 100,
  // 100, 100, 100, 100, 100, 100, 100
};

Frame fadeFrames[]= {
    Frame(
      0x00000000,
      0x00000000,
      0x00000000,
      0x00000000,
      0x00000000,
      0x00000000,
      0x00000000,
      0x00000000
    ),
    Frame(
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111
    ),
    Frame(
      0x22222222,
      0x22222222,
      0x22222222,
      0x22222222,
      0x22222222,
      0x22222222,
      0x22222222,
      0x22222222
    ),
    Frame(
      0x33333333,
      0x33333333,
      0x33333333,
      0x33333333,
      0x33333333,
      0x33333333,
      0x33333333,
      0x33333333
    ),
    Frame(
      0x44444444,
      0x44444444,
      0x44444444,
      0x44444444,
      0x44444444,
      0x44444444,
      0x44444444,
      0x44444444
    ),
    Frame(
      0x55555555,
      0x55555555,
      0x55555555,
      0x55555555,
      0x55555555,
      0x55555555,
      0x55555555,
      0x55555555
    ),
    Frame(
      0x66666666,
      0x66666666,
      0x66666666,
      0x66666666,
      0x66666666,
      0x66666666,
      0x66666666,
      0x66666666
    ),
    Frame(
      0x77777777,
      0x77777777,
      0x77777777,
      0x77777777,
      0x77777777,
      0x77777777,
      0x77777777,
      0x77777777
    ),
    Frame(
      0x88888888,
      0x88888888,
      0x88888888,
      0x88888888,
      0x88888888,
      0x88888888,
      0x88888888,
      0x88888888
    ),
    Frame(
      0x99999999,
      0x99999999,
      0x99999999,
      0x99999999,
      0x99999999,
      0x99999999,
      0x99999999,
      0x99999999
    ),
    Frame(
      0xAAAAAAAA,
      0xAAAAAAAA,
      0xAAAAAAAA,
      0xAAAAAAAA,
      0xAAAAAAAA,
      0xAAAAAAAA,
      0xAAAAAAAA,
      0xAAAAAAAA
    ),
    Frame(
      0xBBBBBBBB,
      0xBBBBBBBB,
      0xBBBBBBBB,
      0xBBBBBBBB,
      0xBBBBBBBB,
      0xBBBBBBBB,
      0xBBBBBBBB,
      0xBBBBBBBB
    ),
    Frame(
      0xCCCCCCCC,
      0xCCCCCCCC,
      0xCCCCCCCC,
      0xCCCCCCCC,
      0xCCCCCCCC,
      0xCCCCCCCC,
      0xCCCCCCCC,
      0xCCCCCCCC
    ),
    Frame(
      0xDDDDDDDD,
      0xDDDDDDDD,
      0xDDDDDDDD,
      0xDDDDDDDD,
      0xDDDDDDDD,
      0xDDDDDDDD,
      0xDDDDDDDD,
      0xDDDDDDDD
    ),
    Frame(
      0xEEEEEEEE,
      0xEEEEEEEE,
      0xEEEEEEEE,
      0xEEEEEEEE,
      0xEEEEEEEE,
      0xEEEEEEEE,
      0xEEEEEEEE,
      0xEEEEEEEE
    ),
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
    // ,
    // Frame(
    //   0xEEEEEEEE,
    //   0xEEEEEEEE,
    //   0xEEEEEEEE,
    //   0xEEEEEEEE,
    //   0xEEEEEEEE,
    //   0xEEEEEEEE,
    //   0xEEEEEEEE,
    //   0xEEEEEEEE
    // ),
    // Frame(
    //   0xDDDDDDDD,
    //   0xDDDDDDDD,
    //   0xDDDDDDDD,
    //   0xDDDDDDDD,
    //   0xDDDDDDDD,
    //   0xDDDDDDDD,
    //   0xDDDDDDDD,
    //   0xDDDDDDDD
    // ),
    // Frame(
    //   0xCCCCCCCC,
    //   0xCCCCCCCC,
    //   0xCCCCCCCC,
    //   0xCCCCCCCC,
    //   0xCCCCCCCC,
    //   0xCCCCCCCC,
    //   0xCCCCCCCC,
    //   0xCCCCCCCC
    // ),
    // Frame(
    //   0xBBBBBBBB,
    //   0xBBBBBBBB,
    //   0xBBBBBBBB,
    //   0xBBBBBBBB,
    //   0xBBBBBBBB,
    //   0xBBBBBBBB,
    //   0xBBBBBBBB,
    //   0xBBBBBBBB
    // ),
    // Frame(
    //   0xAAAAAAAA,
    //   0xAAAAAAAA,
    //   0xAAAAAAAA,
    //   0xAAAAAAAA,
    //   0xAAAAAAAA,
    //   0xAAAAAAAA,
    //   0xAAAAAAAA,
    //   0xAAAAAAAA
    // ),
    // Frame(
    //   0x99999999,
    //   0x99999999,
    //   0x99999999,
    //   0x99999999,
    //   0x99999999,
    //   0x99999999,
    //   0x99999999,
    //   0x99999999
    // ),
    // Frame(
    //   0x88888888,
    //   0x88888888,
    //   0x88888888,
    //   0x88888888,
    //   0x88888888,
    //   0x88888888,
    //   0x88888888,
    //   0x88888888
    // ),
    // Frame(
    //   0x77777777,
    //   0x77777777,
    //   0x77777777,
    //   0x77777777,
    //   0x77777777,
    //   0x77777777,
    //   0x77777777,
    //   0x77777777
    // ),
    // Frame(
    //   0x66666666,
    //   0x66666666,
    //   0x66666666,
    //   0x66666666,
    //   0x66666666,
    //   0x66666666,
    //   0x66666666,
    //   0x66666666
    // ),
    // Frame(
    //   0x55555555,
    //   0x55555555,
    //   0x55555555,
    //   0x55555555,
    //   0x55555555,
    //   0x55555555,
    //   0x55555555,
    //   0x55555555
    // ),
    // Frame(
    //   0x44444444,
    //   0x44444444,
    //   0x44444444,
    //   0x44444444,
    //   0x44444444,
    //   0x44444444,
    //   0x44444444,
    //   0x44444444
    // ),
    // Frame(
    //   0x33333333,
    //   0x33333333,
    //   0x33333333,
    //   0x33333333,
    //   0x33333333,
    //   0x33333333,
    //   0x33333333,
    //   0x33333333
    // ),
    // Frame(
    //   0x22222222,
    //   0x22222222,
    //   0x22222222,
    //   0x22222222,
    //   0x22222222,
    //   0x22222222,
    //   0x22222222,
    //   0x22222222
    // ),
    // Frame(
    //   0x11111111,
    //   0x11111111,
    //   0x11111111,
    //   0x11111111,
    //   0x11111111,
    //   0x11111111,
    //   0x11111111,
    //   0x11111111
    // ),
    // Frame(
    //   0x00000000,
    //   0x00000000,
    //   0x00000000,
    //   0x00000000,
    //   0x00000000,
    //   0x00000000,
    //   0x00000000,
    //   0x00000000
    // )
  };

Animation fade(16, fadeTiming, fadeFrames);
