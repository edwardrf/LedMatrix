void setup(){
  Serial.begin(115200);
  pinMode(3, OUTPUT); // output pin for OCR2B
  pinMode(11, OUTPUT); // output pin for OCR0B
  pinMode(A0, INPUT);
  // digitalWrite(A0, HIGH);

  // Set up the 250KHz output
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = 5;
  OCR2B = 2;
}

// int cnt = 0, sum = 0;
//
// void loop(){
//   cnt ++;
//   sum += digitalRead(A0);
//   if(cnt >= 1000){
//    Serial.println(sum);
//    cnt = 0;
//    sum = 0;
//   }
// }


double ma = 0, peak = 0, cnt = 0;

void loop() {
  ma = (ma * 0.999 + digitalRead(A0) * 0.001);
  if(cnt++ >= 50){
    double d = ma - 0.5;
    if(d < 0) d = -d;
    if(d > peak)
      peak = d;
    else
      peak = 0.9 * peak;
    // peak = 0.9 * peak + 0.1 * d;
    // Serial.println(HIGH);
    // if(peak > 0.03) {
    Serial.println(peak * 100);
    Serial.println(d * 100);
    // }
    cnt = 0;
  }
}
