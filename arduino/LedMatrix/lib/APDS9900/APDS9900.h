// I2Cdev library collection - APDS9900 I2C device class header file
// Based on Analog Devices APDS9900 datasheet rev. C, 5/2011
// 7/31/2011 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
//
// Changelog:
//     2011-07-31 - initial release

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2011 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef _APDS9900_H_
#define _APDS9900_H_

#include "I2Cdev.h"

#define APDS9900_DEFAULT_ADDRESS     0x1E

// Register Addresses
#define APDS9900_ENABLE              0x00
#define APDS9900_ATIME               0x01
#define APDS9900_PTIME               0x02
#define APDS9900_WTIME               0x03
#define APDS9900_AILTL               0x04
#define APDS9900_AILTH               0x05
#define APDS9900_AIHTL               0x06
#define APDS9900_AIHTH               0x07
#define APDS9900_PILTL               0x08
#define APDS9900_PILTH               0x09
#define APDS9900_PIHTL               0x0A
#define APDS9900_PIHTH               0x0B
#define APDS9900_PERS                0x0C
#define APDS9900_CONFIG              0x0D
#define APDS9900_PPCOUNT             0x0E
#define APDS9900_CONTROL             0x0F
#define APDS9900_REV                 0x11
#define APDS9900_ID                  0x12
#define APDS9900_STATUS              0x13
#define APDS9900_CDATAL              0x14
#define APDS9900_CDATAH              0x15
#define APDS9900_IRDATAL             0x16
#define APDS9900_IRDATAH             0x17
#define APDS9900_PDATAL              0x18
#define APDS9900_PDATAH              0x19


// Register Bits
#define APDS9900_ENABLE_PIEN_BIT     5
#define APDS9900_ENABLE_AIEN_BIT     4
#define APDS9900_ENABLE_WEN_BIT      3
#define APDS9900_ENABLE_PEN_BIT      2
#define APDS9900_ENABLE_AEN_BIT      1
#define APDS9900_ENABLE_PON_BIT      0

#define APDS9900_PERS_APERS_BIT      7
#define APDS9900_PERS_APERS_LENGTH   4
#define APDS9900_PERS_PPERS_BIT      3
#define APDS9900_PERS_PPERS_LENGTH   4

#define APDS9900_CONFIG_WLONG_BIT    1

#define APDS9900_CONTROL_PDRIVE_BIT     7
#define APDS9900_CONTROL_PDRIVE_LENGTH  2
#define APDS9900_CONTROL_PDOIDE_BIT     5
#define APDS9900_CONTROL_PDOIDE_LENGTH  2
#define APDS9900_CONTROL_PGAIN_BIT      3
#define APDS9900_CONTROL_PGAIN_LENGTH   2
#define APDS9900_CONTROL_AGAIN_BIT      1
#define APDS9900_CONTROL_AGAIN_LENGTH   2

#define APDS9900_STATUS_PINT_BIT    5
#define APDS9900_STATUS_AINT_BIT    4
#define APDS9900_STATUS_PVALID_BIT  1
#define APDS9900_STATUS_AVALID_BIT  0


// Register Values
#define APDS9900_CONTROL_PDRIVE_100MA  0x00
#define APDS9900_CONTROL_PDRIVE_50MA   0x40
#define APDS9900_CONTROL_PDRIVE_25MA   0x80
#define APDS9900_CONTROL_PDRIVE_12MA   0xC0

#define APDS9900_CONTROL_PDIODE_CH1    0x20

#define APDS9900_CONTROL_PGAIN_1       0x00

#define APDS9900_CONTROL_AGAIN_1       0x00
#define APDS9900_CONTROL_AGAIN_8       0x01
#define APDS9900_CONTROL_AGAIN_16      0x02
#define APDS9900_CONTROL_AGAIN_120     0x03


class APDS9900 {
  public:
    APDS9900();
    APDS9900(uint8_t address);

    void initialize();
    bool testConnection();

    // DEVID register
    uint8_t getDeviceID();

    unsigned int getChannel0();
    unsigned int getChannel1();
    unsigned int getProximity();

    unsigned int getLux();

  private:
    uint8_t devAddr;
    uint8_t buffer[6];
};

#endif /* _APDS9900_H_ */

/*
// Official psudo code
uint8 ATIME, PIME, WTIME, PPCOUNT;
ATIME = 0xff; // 2.7 ms – minimum ALS integration time
WTIME = 0xff; // 2.7 ms – minimum Wait time
PTIME = 0xff; // 2.7 ms – minimum Prox integration time
PPCOUNT = 1; // Minimum prox pulse count
WriteRegData(0, 0); //Disable and Powerdown
WriteRegData (1, ATIME);
WriteRegData (2, PTIME);
WriteRegData (3, WTIME);
WriteRegData (0xe, PPCOUNT);
uint8 PDRIVE, PDIODE, PGAIN, AGAIN;
PDRIVE = 0; //100mA of LED Power
PDIODE = 0x20; // CH1 Diode
PGAIN = 0; //1x Prox gain
AGAIN = 0; //1x ALS gain
WriteRegData (0xf, PDRIVE | PDIODE | PGAIN | AGAIN);
uint8 WEN, PEN, AEN, PON;
WEN = 8; // Enable Wait
PEN = 4; // Enable Prox
AEN = 2; // Enable ALS
PON = 1; // Enable Power On
WriteRegData (0, WEN | PEN | AEN | PON); // WriteRegData(0,0x0f );
Wait(12); //Wait for 12 ms
int CH0_data, CH1_data, Prox_data;
CH0_data = Read_Word(0x14);
CH1_data = Read_Word(0x16);
Prox_data = Read_Word(0x18);
WriteRegData(uint8 reg, uint8 data)
{
  m_I2CBus.WriteI2C(0x39, 0x80 | reg, 1, &data);
}
uint16 Read_Word(uint8 reg);
{
  uint8 barr[2];
  m_I2CBus.ReadI2C(0x39, 0xA0 | reg, 2, ref barr);
  return (uint16)(barr[0] + 256 * barr[1]);
}
*/
