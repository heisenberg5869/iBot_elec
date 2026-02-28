// Task 2.0.1: Blink - Verify ESP32 is working
// Built-in LED is typically Pin 2 on ESP32

#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}