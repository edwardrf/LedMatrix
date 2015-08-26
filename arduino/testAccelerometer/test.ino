#include <ADXL345.h>

ADXL345 accel;

int16_t ax, ay, az;
//
// // #define LED_PIN 13 // (Arduino is 13, Teensy is 6)
// bool blinkState = false;

void setup() {
    // pinMode(A3, OUTPUT);
    // pinMode(13, OUTPUT);
    // digitalWrite(A3, LOW);
    // digitalWrite(13, LOW);
    // join I2C bus (I2Cdev library doesn't do this automatically)
    digitalWrite(A7, LOW);
    Wire.begin();
    //
    // // initialize serial communication
    // // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // // it's really up to you depending on your project)
    // delay(4000);
    Serial.begin(115200);

    // initialize device
    Serial.println("Initializing I2C devices...");
    accel.initialize();
    // accel.setLowPowerEnabled(true);
    accel.setOffset(-54, -38, -47);
    // accel.setOffset(0, 0, 0);

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accel.testConnection() ? "ADXL345 connection successful" : "ADXL345 connection failed");
    Serial.print("Range : ");
    Serial.println(accel.getRange() );

    // configure LED for output
    // pinMode(LED_PIN, OUTPUT);

    // -== MICROPHONE ==-
    pinMode(11, OUTPUT);
    // Set up the 2Mhz output
    TCCR2A = _BV(COM2A0) | _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(WGM22) | _BV(CS20);
    OCR2A = 1;
}

int lv;
void loop() {
  // read raw accel measurements from device
  accel.getAcceleration(&ax, &ay, &az);
  int v = analogRead(A7);
  int v2 = analogRead(A6);
  //
  // display tab-separated accel x/y/z values
  Serial.print("accel:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.println();

    // Serial.print("\tSound:\t");
    // Serial.println(v);
  if((v > lv && v - lv > 8) || (v < lv && lv - v > 8)) {
  // if(v - 338 > 3 || 338 - v > 3) {
    Serial.print("\t======= DELTA Sound:\t");
    Serial.println(v - lv);
    // Serial.print("\tLight:\t");
    // Serial.println(v2);
  }
  lv = v;

  // blink LED to indicate activity
  // blinkState = !blinkState;
  // digitalWrite(LED_PIN, blinkState);
  delay(10);
}
