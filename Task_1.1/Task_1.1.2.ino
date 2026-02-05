int ldr = A0;
void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
}

void loop() {
  int lightLevel = analogRead(ldr);
  Serial.println(lightLevel);
  delay(100);
}