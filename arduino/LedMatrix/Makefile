# BOARD_TAG    = mega
AVRDUDE_OPTS  = -q -V # Default option includes -D which prvents ispload from erasing
BOARD_TAG     = pro328
MONITOR_PORT  = /dev/ttyUSB*
ISP_PROG     	= usbasp
USER_LIB_PATH = $(realpath ./lib)
ARDUINO_LIBS  = TimerOne ADXL345 I2Cdev Wire

include /usr/share/arduino/Arduino.mk
