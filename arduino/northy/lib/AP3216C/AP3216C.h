// I2Cdev library collection - AP3216C I2C device class header file
// Based on Analog Devices AP3216C datasheet rev. C, 5/2011
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

#ifndef _AP3216C_H_
#define _AP3216C_H_

#include "I2Cdev.h"

#define AP3216C_DEFAULT_ADDRESS     0x1E

// Register Addresses
// System Register Table
#define AP3216C_SYS_CONF            0x00
#define AP3216C_INT_STATUS          0x01
#define AP3216C_INT_CLEAR_MANNER    0x02
#define AP3216C_IR_DATA_LOW         0x0A
#define AP3216C_IR_DATA_HIGH        0x0B
#define AP3216C_ALS_DATA_LOW        0x0C
#define AP3216C_ALS_DATA_HIGH       0x0D
#define AP3216C_PS_DATA_LOW         0x0E
#define AP3216C_PS_DATA_HIGH        0x0F
// ALS Register Table
#define AP3216C_ALS_CONF            0x10
#define AP3216C_ALS_CALIBRATION     0x19 // Calibration factor = v/64
#define AP3216C_ALS_LOW_TRESH_L     0x1A
#define AP3216C_ALS_LOW_TRESH_H     0x1B
#define AP3216C_ALS_HIGH_TRESH_L    0x1C
#define AP3216C_ALS_HIGH_TRESH_H    0x1D
// PS Register Table
#define AP3216C_PS_CONF             0x20
#define AP3216C_PS_LED_DRIVER       0x21
#define AP3216C_PS_INT_FORM         0x22
#define AP3216C_PS_MEAN_TIME        0x23
#define AP3216C_PS_LED_WAIT_TIME    0x24 // v * mean time 0x3F max
#define AP3216C_PS_CALIBRATION_L    0x28
#define AP3216C_PS_CALIBRATION_H    0x29
#define AP3216C_PS_LOW_TRESH_L      0x2A
#define AP3216C_PS_LOW_TRESH_H      0x2B
#define AP3216C_PS_HIGH_TRESH_L     0x2C
#define AP3216C_PS_HIGH_TRESH_H     0x2D

// System register Values
// SYS_CONF values
#define AP3216C_MODE_POWER_DOWN     0x00
#define AP3216C_MODE_ALS            0x01
#define AP3216C_MODE_PS_IR          0x02
#define AP3216C_MODE_ALS_PS_IR      0x03
#define AP3216C_MODE_SW_RESET       0x04
#define AP3216C_MODE_ALS_ONCE       0x05
#define AP3216C_MODE_PS_IR_ONCE     0x06
#define AP3216C_MODE_ALS_PS_IR_ONCE 0x07
// INT_STATUS bits and values
#define AP3216C_INT_ALS_BIT         0
#define AP3216C_INT_PS_BIT          1
#define AP3216C_INT_CLEARED         0x00
#define AP3216C_INT_TRIGGERED       0x01
// INT_CLEAR_MANNER values
#define AP3216C_INT_CLEAR_AUTO      0x00
#define AP3216C_INT_CLEAR_SOFT      0x01
// IR_DATA_LOW bits and values
#define AP3216C_IR_LOW_OVFL_BIT     7
#define AP3216C_IR_LOW_OVFL_VALID   0x00
#define AP3216C_IR_LOW_OVFL_INVALID 0x01
// PS_DATA bits and values
#define AP3216C_PS_OBJ_DETECT_BIT   7
#define AP3216C_PS_IR_OVFL_BIT      6
#define AP3216C_PS_OBJ_LEFT         0x00
#define AP3216C_PS_OBJ_CLOSE        0x01

// ALS registers
// Conf bits and values
#define AP3216C_ALS_DYN_RANGE_BIT   4 // [5:4]
#define AP3216C_ALS_DYN_RANGE_20k   0x00
#define AP3216C_ALS_DYN_RANGE_5k    0x01
#define AP3216C_ALS_DYN_RANGE_1k    0x10
#define AP3216C_ALS_DYN_RANGE_300   0x11
#define AP3216C_ALS_DYN_RANGE_BIT   4
#define AP3216C_ALS_PERSIST_BIT     0 // v * 4 conversion time, except 0 -> 1

// PS registers
// Conf bits and values
#define AP3216C_PS_CONF_TIME_BIT    4 // [7:4] T units
#define AP3216C_PS_CONF_GAIN_BIT    2 // [3:2] 2^v default to 2^1=2
#define AP3216C_PS_CONF_PERSIST_BIT 0 // [1:0] trigger after 2^v conversion time default to 2^1=2
// Led control
#define AP3216C_PS_LED_PULSE_BIT    4 // [5:4] number of pulses
#define AP3216C_PS_LED_RATIO_BIT    0 // [1:0] 16.7%, 33.3%, 66.7%, 100%
// Led interrupt mode
#define AP3216C_PS_INT_MODE_ZONE    0x00
#define AP3216C_PS_INT_MODE_HYST    0x01
// PS mean time values
#define AP3216C_PS_MEAN_TIME_12ms   0x00 // Default
#define AP3216C_PS_MEAN_TIME_25ms   0x01
#define AP3216C_PS_MEAN_TIME_37ms   0x10
#define AP3216C_PS_MEAN_TIME_50ms   0x11

class AP3216C {
  public:
    AP3216C();
    AP3216C(uint8_t address);

    void initialize();
    void setAlsGain(uint8_t g);

    unsigned int getInfraRed();
    unsigned int getAmbientLight();
    unsigned int getProximity();

  private:
    uint8_t devAddr;
    uint8_t buffer[6];
};

#endif /* _AP3216C_H_ */

