int InputPin = 10;
int OutputPin = 9;
void setup() {
  Serial.begin(9600);
  pinMode(InputPin, OUTPUT);
  pinMode(OutputPin, INPUT);
}

void loop() {
  digitalWrite(OutputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(OutputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(OutputPin, LOW);
  
  long duration = pulseIn(InputPin, HIGH);
  float distance = duration * (0.0343 / 2);
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(200);
}