//IO test Steve Lomax 23/11/2025
char userin;
char dump;
void setup() {
  Serial.begin(19200);
  Serial.println("\n\n\nArduino Tester. Steve Lomax Nov 2025\n");
  Serial.println("enter '1' for general I/O");
  Serial.println("enter '2' for A6 & A7");
  Serial.println("enter '3' for Onboard LED");
  for (int i = 2; i < 20; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  pinMode(13,OUTPUT);
}
void D13() {
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
}
void A67() {
  Serial.print("A6 = ");
  Serial.print(analogRead(A6));
  Serial.print("    A7 = ");
  Serial.println(analogRead(A7));
}
void ScanIO() {


  for (int i = 2; i < 20; i++) {
    if (i != 13) {
      if (!digitalRead(i)) {

        bool pwm = (i == 3 || i == 5 || i == 6 || i == 9 || i == 10 || i == 11);
        delay(20);
        pinMode(i, OUTPUT);
        Serial.print("Found pin ");
        Serial.print(i);
        if (pwm) {
          Serial.println(" pwm should fade up");
          for (int value = 0; value <= 255; value++) {
            analogWrite(i, value);
            delay(5);
          }
        } else {
          Serial.println("");
          digitalWrite(i, HIGH);
          delay(1500);
        }
        digitalWrite(i, LOW);
        delay(200);
        pinMode(i, INPUT_PULLUP);
        delay(100);
      }
    }
  }
}
void loop() {

  if (Serial.available()) {

    userin = Serial.read();
    Serial.print(userin);
    Serial.println();
    while (Serial.available()) {
      Serial.read();
    }


    switch (userin) {
      case '1':
        Serial.println("General I/O connect test LED between GND and pin");
        break;
      case '2':
        Serial.println("Readimg A6 and A7 ");
        break;
      case '3':
        Serial.println("Flashing onboard LED ");
        break;
      case '\r':
        break;
      case '\n':
        break;
      default:
        Serial.println("Unknown entry");
        Serial.println("Enter '1' for general I/O");
        Serial.println("      '2' for A6 & A7");
        Serial.println("      '3' for Onboard LED");
    }
  }
  delay(50);
  // Serial.print(userin);
  // Serial.println();

  switch (userin) {
    case '1':
      ScanIO();
      break;
    case '2':
      A67();
      break;
    case '3':
      D13();
      break;
    default:
      ScanIO();
  }
}
