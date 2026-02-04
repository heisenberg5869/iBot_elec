int ledPin = 9;
int buttonPin = 2;
bool ledState = LOW;
bool prevButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == LOW && prevButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50); 
  }
  prevButtonState = currentButtonState;
}