// Task 2.2.1: Bluetooth Serial (SPP) LED control (OFF)
#include "BluetoothSerial.h"

#define LED_PIN 2

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  SerialBT.begin("ESP32_sarr");  
  Serial.println("Bluetooth started. Waiting for connection...");
}

void loop() {
  if (SerialBT.available()) {
    char val = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(val);

    if (val == '1') {
      digitalWrite(LED_PIN, HIGH);
      SerialBT.println("LED is ON");
      Serial.println("LED ON");
    } else if (val == '0') {
      digitalWrite(LED_PIN, LOW);
      SerialBT.println("LED is OFF");
      Serial.println("LED OFF");
    }
  }
}d