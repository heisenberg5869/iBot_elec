int ir = A0;
void setup() {
  Serial.begin(9600);
  pinMode(ir, INPUT);
}

void loop() {
  int sensorValue = analogRead(ir);
  Serial.println(sensorValue);
  if (sensorValue >= 305){
    Serial.println("White color");
  }
  else {
    Serial.println("Black color");
  }
  delay(500);
}
