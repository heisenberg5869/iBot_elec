void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(A0);
  Serial.println(lightLevel);
  delay(100);
}