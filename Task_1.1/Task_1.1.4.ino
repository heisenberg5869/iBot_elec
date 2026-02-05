int trig = 10;
int echo = 9;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  long duration = pulseIn(echo, HIGH);
  float distance = duration * (0.0343 / 2);
  
  Serial.print(distance);
  Serial.println(" cm");
  delay(200);
}