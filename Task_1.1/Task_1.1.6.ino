const int flamePin = A0; 

void setup() {
  Serial.begin(9600);
  pinMode(flamePin, INPUT);
}

void loop() {
  int irValue = analogRead(flamePin);
  Serial.print("IR Intensity: ");
  Serial.println(irValue);
  delay(100); 
}