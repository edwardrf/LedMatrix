void setup() {
  Serial.begin(115200);
  Serial.println("Initializing ...");
  // delay(1000);
  // pinMode(5, OUTPUT);
  // pinMode(7, OUTPUT);
  // analogWrite(5, 64);
  // for(int i = 0; i < 10; i++) {
  //   digitalWrite(7, HIGH);
  //   delay(25);
  //   digitalWrite(7, LOW);
  //   delay(25);
  // }
  // analogWrite(5, 192);
}

void loop() {
  // digitalWrite(7, HIGH);
  // delay(5);
  // digitalWrite(7, LOW);
  // delay(5);
  Serial.println("Hello !!!");
  if (Serial.available() > 0) {
      int incomingByte = Serial.read();
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);
  }
  delay(1000);
}
