#include "animation.h"
#include <avr/pgmspace.h>

const Frame northyFrames[] PROGMEM = {


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xFF0000FF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xF0F00F0F,
        0xFFF00FFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xF0F00F0F,
        0xF0F00F0F,
        0xFF0000FF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xF0F00F0F,
        0xF0F00F0F,
        0xF0F00F0F,
        0xFFF00FFF,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      1000
    },


    {
      {
        0xFFFFFFFF,
        0xF0F00F0F,
        0xF0F00F0F,
        0xFF0000FF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xF0F00F0F,
        0xFFF00FFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xFF0000FF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      500
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFF00000F,
        0xFF00000F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFF0000F,
        0xFFF0000F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF0FF000F,
        0xF0FF000F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      250
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      100
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      200
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      200
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      100
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      200
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      400
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000FF0F,
        0xF000FF0F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF0000FFF,
        0xF0000FFF,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000FF0F,
        0xF000FF0F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      100
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      200
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      200
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      100
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      200
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF00FF00F,
        0xF00FF00F,
        0xF000000F,
        0xFFFFFFFF
      },
      400
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF0FF000F,
        0xF0FF000F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFF0000F,
        0xFFF0000F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFF00000F,
        0xFF00000F,
        0xF000000F,
        0xFFFFFFFF
      },
      150
    },


    {
      {
        0xFFFFFFFF,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xF000000F,
        0xFFFFFFFF
      },
      500
    }



  };


Animation northy = {33, northyFrames};
