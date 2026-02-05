const int buzzpin = 9;
void setup() {
  pinMode(buzzpin, INPUT);
}

void loop() {
  tone(buzzpin, 1000);
  delay(1000);
  noTone(buzzpin);
}

