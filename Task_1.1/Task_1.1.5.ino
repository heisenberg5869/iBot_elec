const int soundPin = A0;     
const int ledPin = 13;  
const int threshold = 100;   

void setup() {
  pinMode(soundPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(soundPin);

  if (sensorValue >= threshold) {
    Serial.println("Clap Detected!");
    digitalWrite(ledPin, HIGH); 
    delay(1000);                
    digitalWrite(ledPin, LOW);  
  }
}