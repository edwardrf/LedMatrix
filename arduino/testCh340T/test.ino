void setup() {
  Serial.begin(115200);
  Serial.println("Initializing ...");
}

int i = 0;
void loop() {
  Serial.print(i++);
  Serial.println("\tHello !!!");
  delay(1000);
}
