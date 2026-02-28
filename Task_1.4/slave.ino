// LASER PROTECTION SYSTEM (SLAVE)
#include <Wire.h>

const int ledPins[] = {3, 5, 6};    //pwm pins for varying brightness
const int buzzerPins[] = {9, 10};   //pins for buzzers
bool alarmActive = false;

void setup() {
  Wire.begin(8); 
  
  for(int i=0; i<3; i++) pinMode(ledPins[i], OUTPUT);
  for(int i=0; i<2; i++) pinMode(buzzerPins[i], OUTPUT);
}

void loop() {
    if (Wire.available()) {
        int command = Wire.read();
        if (command == 1) {
        alarmActive = true;
        } else if (command == 0) {
        alarmActive = false;
        }
    }
    if (alarmActive) {
        for(int i=0; i<3; i++) {
        analogWrite(ledPins[i], random(0, 255));
        }

        tone(buzzerPins[0], random(400, 1200));
        tone(buzzerPins[1], random(400, 1200));
        
        delay(20); 
    } else {
        for(int i=0; i<3; i++) analogWrite(ledPins[i], 0);
        noTone(buzzerPins[0]);
        noTone(buzzerPins[1]);
    }
}
