// I2Cdev library collection - AP3216C I2C device class
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

#include "AP3216C.h"

AP3216C::AP3216C() {
    devAddr = AP3216C_DEFAULT_ADDRESS;
}

AP3216C::AP3216C(uint8_t address) {
    devAddr = address;
}

/**
 * Initialize to a simple state
 */
void AP3216C::initialize() {
  I2Cdev::writeByte(devAddr, AP3216C_PS_LED_WAIT_TIME, 0x04); // Only do proximity every 4 periods
  //I2Cdev::writeByte(devAddr, AP3216C_PS_LED_DRIVER, 0x00); // Only do proximity every 4 periods
  I2Cdev::writeByte(devAddr, AP3216C_SYS_CONF, AP3216C_MODE_ALS); //Enable all functions
}

void AP3216C::setAlsGain(uint8_t g){
  I2Cdev::writeByte(devAddr, AP3216C_ALS_CONF, (g & 0x03) << AP3216C_ALS_DYN_RANGE_BIT); // Only do proximity every 4 periods
}

unsigned int AP3216C::getInfraRed(){
  uint8_t buf[2];
  I2Cdev::readBytes(devAddr, AP3216C_IR_DATA_LOW, 2, buf);
  //return (unsigned int)(4 * buf[1]);
  return (unsigned int)((buf[0] & 0x03) + 4 * buf[1]);
}

unsigned int AP3216C::getAmbientLight(){
  uint8_t buf[2];
  I2Cdev::readBytes(devAddr, AP3216C_ALS_DATA_LOW, 2, buf);
  //return (unsigned int)(4 * buf[1]);
  return (unsigned int)((buf[0] & 0x03) + 4 * buf[1]);
}

unsigned int AP3216C::getProximity(){
  uint8_t buf[2];
  I2Cdev::readBytes(devAddr, AP3216C_PS_DATA_LOW, 2, buf);
  //return (unsigned int)(4 * buf[1]);
  return (unsigned int)((buf[0] & 0x03) + 4 * buf[1]);
}

