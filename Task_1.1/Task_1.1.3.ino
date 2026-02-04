int PIRPin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);
}

void loop() {
  int motion = digitalRead(PIRPin);
  Serial.println(motion);
  delay(100);
}