#include <ADXL345.h>
#include <EEPROM.h>

ADXL345 accel;

int16_t ax, ay, az;
//
// // #define LED_PIN 13 // (Arduino is 13, Teensy is 6)
// bool blinkState = false;

void setup() {
  pinMode(A6, INPUT); // ambient light reading
  pinMode(A7, INPUT); // sound level reading
  digitalWrite(A3, LOW);

  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  Serial.begin(115200);

  // initialize device
  Serial.println("Initializing I2C devices...");
  accel.initialize();
  //accel.setRange(0); // 2g range
  accel.setRange(3); // 16g range
  accel.setFullResolution(1);

  // Test
  Serial.println("Testing device connections...");
  Serial.println(accel.testConnection() ? "ADXL345 connection successful" : "ADXL345 connection failed");
  Serial.print("Range : ");
  Serial.println(accel.getRange());
  Serial.print("Full Resolution : ");
  Serial.println(accel.getFullResolution());

  // Retrive previous calibration value if exists
  int8_t calibrated = EEPROM.read(0);
  int8_t xoffset = 0;
  int8_t yoffset = 0;
  int8_t zoffset = 0;
  if(calibrated == 0xCA){
    xoffset = EEPROM.read(1);
    yoffset = EEPROM.read(2);
    zoffset = EEPROM.read(3);
  }
  Serial.print("Previous OFFSETS\tx:");
  Serial.print(xoffset); Serial.print("\ty:");
  Serial.print(yoffset); Serial.print("\tz:");
  Serial.print(zoffset);
  Serial.println();

  // Set offset to 0 to recalibrate
  accel.setOffset(0,0,0);

  // Calibration
  Serial.println("======= About to calibrate accelerometer, place the device face down flat on the table =======");
  Serial.println("======= Start and warm up =======");
  // Discard the first 200 readings
  for(int i = 0; i < 200; i ++) {
    accel.getAcceleration(&ax, &ay, &az);
    Serial.print("accel:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.println();
    delay(5);
  }
  Serial.println("======= Sampling start =======");
  int sampleSize = 500;
  double sx = 0, sy = 0, sz = 0;
  for(int i = 0; i < sampleSize; i ++) {
    accel.getAcceleration(&ax, &ay, &az);
    Serial.print("accel:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.print(az); Serial.println();
    sx += ax;
    sy += ay;
    sz += az;
    delay(1);
  }
  Serial.println("======= Calibration result =======");
  // The offset register has a resolution of 15.6mg/LSB
  // At 2g range, the readings has a range of 3.9mg/LSB thus, the value needs to be devided by 4;
  xoffset = -sx / sampleSize / 4;
  yoffset = -sy / sampleSize / 4;
  //zoffset = (-sz / sampleSize - 255) / 4;
  zoffset = ((-sz) / sampleSize - 255) / 4.0;

  Serial.print("Total offsets\tx:");
  Serial.print(sx); Serial.print("\ty:");
  Serial.print(sy); Serial.print("\tz:");
  Serial.print((-sz) / sampleSize); Serial.print("\tz:");
  Serial.print((-sz) / sampleSize - 255); Serial.print("\tz:");
  Serial.print(((-sz) / sampleSize - 255) / 4); Serial.print("\tz:");
  Serial.print(zoffset); Serial.print("\tz:");
  Serial.print(sz);
  Serial.println();
  
  // At 16g range, the readings has a range of 3.9 * 8 = 31.2mg/LSB thus, the value needs to be multiply by 2;
  // xoffset = -sx / sampleSize * 2;
  // yoffset = -sy / sampleSize * 2;
  // zoffset = (-sz / sampleSize - 32) * 2;
  //zoffset = -127;

  accel.setOffset(xoffset, yoffset, zoffset);
  Serial.print("Accel OFFSETS\tx:");
  Serial.print(xoffset); Serial.print("\ty:");
  Serial.print(yoffset); Serial.print("\tz:");
  Serial.print(zoffset);
  Serial.println();
  Serial.println();

  // Record the calibration offset
  Serial.println("======= Calibration result =======");
  EEPROM.write(0, 0xCA);
  EEPROM.write(1, xoffset);
  EEPROM.write(2, yoffset);
  EEPROM.write(3, zoffset);

  // -== MICROPHONE ==-
  pinMode(11, OUTPUT);
  // Set up the 2Mhz output
  TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = 1;

  // Setup LED control
  DDRD   = B11111111; // Whole port D is output
  PORTD  = B00000000; // Turn off all led HIGH side
  DDRB  |= B00000111; // PB0~PB2 controls the demultiplexer
  PORTB &= B11111000;
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);

  delay(500);
}

int linePointer = 0;
void loop() {
  // Turn on LED
  PORTD = 0;
  PORTB &= B11111000;   // Clear
  PORTB |= linePointer; // Then set
  // Turn on the HIGH side through PORTD
  PORTD = B11111111;

  // Advance to next line
  linePointer ++;
  if(linePointer >= 8) {
    linePointer = 0;
  }

  // read raw accel measurements from device
  accel.getAcceleration(&ax, &ay, &az);
  int sound = analogRead(A7);
  int light = analogRead(A6);
  //
  // display tab-separated accel x/y/z values
  Serial.print("                                                                                                                               \r");
  Serial.print("accel:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); //Serial.println();
  Serial.print("\tLIGHT === \t");
  Serial.print(light);
  Serial.print("\tSound:\t");
  Serial.print(sound);
  Serial.print("\r");


  // Turn off LED
  delay(10);
  // delayMicroseconds(10);
}
