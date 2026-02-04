const int soundPin = 2;     
const int ledPin = 13;     

void setup() {
  pinMode(soundPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(soundPin);

  if (sensorValue == HIGH) {
    Serial.println("Clap Detected!");
    digitalWrite(ledPin, HIGH); 
    delay(2000);                
    digitalWrite(ledPin, LOW);  
  }
}