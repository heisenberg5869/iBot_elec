int ir = a0;
void setup() {
  Serial.begin(9600);
  pinMode(ir, INPUT);
}

void loop() {
  int sensorValue = analogRead(ir);
  Serial.println(sensorValue);
  if (sensorValue >= 500){
    Serial.println("White color detected");
  }
  else {
    Serial.println("Black color detected");
  }
  delay(500);
}