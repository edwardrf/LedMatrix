// I2Cdev library collection - APDS9900 I2C device class
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

#include "APDS9900.h"

APDS9900::APDS9900() {
    devAddr = APDS9900_DEFAULT_ADDRESS;
}

APDS9900::APDS9900(uint8_t address) {
    devAddr = address;
}

/**
 * Initialize to a simple state
 */
void APDS9900::initialize() {
  I2Cdev::writeByte(devAddr, APDS9900_ENABLE, 0); //Disable and Powerdown
// Serial.print("CTRL");Serial.println(    APDS9900_CONTROL_PDRIVE_12MA |
//     APDS9900_CONTROL_PDIODE_CH1 |
//     APDS9900_CONTROL_PGAIN_1 |
//     APDS9900_CONTROL_AGAIN_1);
  // Config timings and power
  I2Cdev::writeByte(devAddr, APDS9900_ATIME, 0xff); // 2.72ms
  I2Cdev::writeByte(devAddr, APDS9900_PTIME, 0xff); // recommended value
  I2Cdev::writeByte(devAddr, APDS9900_WTIME, 0xff); // 2.72ms
  I2Cdev::writeByte(devAddr, APDS9900_PPCOUNT, 255);
  I2Cdev::writeByte(devAddr, APDS9900_CONTROL,
    APDS9900_CONTROL_PDRIVE_12MA |
    APDS9900_CONTROL_PDIODE_CH1 |
    APDS9900_CONTROL_PGAIN_1 |
    APDS9900_CONTROL_AGAIN_1
  );
  // Turn the device on with W, P, A all on
  I2Cdev::writeByte(devAddr, APDS9900_ENABLE, 0x0f); //WEN | PEN | AEN | PON); // WriteRegData(0,0x0f );
}

bool APDS9900::testConnection() {
    return getDeviceID() == 0x29;
}

uint8_t APDS9900::getDeviceID() {
  // uint8_t buf[1];
  // for(uint8_t i = 31; i < 127; i++){
  //   Serial.print(i);Serial.println(" ================");
    // for(uint8_t d = 0; d < 0x20; d++){
  I2Cdev::readByte(devAddr, APDS9900_ID, buffer);
      // I2Cdev::readByte(30, d, buf);
      // Serial.print(buf[0]); Serial.print('\t');
  //     delay(10);
    // }
  //   Serial.println("-----------------------");
  //   delay(100);
  // }
  return buffer[0];
}

unsigned int APDS9900::getChannel0(){
  uint8_t buf[2];
  // I2Cdev::readBytes(devAddr, APDS9900_CDATAL, 2, buf);
  I2Cdev::readBytes(devAddr, 10, 2, buf);
  return (unsigned int)(buf[0] + 256 * buf[1]);
}

unsigned int APDS9900::getChannel1(){
  uint8_t buf[2];
  // I2Cdev::readBytes(devAddr, APDS9900_IRDATAL, 2, buf);
  I2Cdev::readBytes(devAddr, 12, 2, buf);
  return (unsigned int)(buf[0] + 256 * buf[1]);
}

unsigned int APDS9900::getProximity(){
  uint8_t buf[2];
  // I2Cdev::readBytes(devAddr, APDS9900_PDATAL, 2, buf);
  I2Cdev::readBytes(devAddr, 14, 2, buf);
  return (unsigned int)(buf[0] + 256 * buf[1]);
}

unsigned int APDS9900::getLux(){
  return getChannel1(); // Not accurate, but good enough
}
