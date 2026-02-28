// LASER PROTECTION SYSTEM(MASTER)
#include <Wire.h>

const int laserpin  = 9;
const int ldrpin    = A0; // ldr is uses analog pin 
bool last_button_state = HIGH;
const int buttonpin = 3; 
const int ldrthreshold = 500; // if it is blocked, value drops
const int warningled = 10; // if ppl blocked, this will light up and give 4 seconds of time to confirm that they are ppl

void setup() {
  Wire.begin(8); // this 8 is the address of the slave (i2c)

  pinMode(ldrpin, INPUT);
  pinMode(laserpin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP); // to make sure the button is always HIGH and if the button is pressed it will go to LOW

  digitalWrite(laserpin, HIGH);
}


void loop() {
  int ldr = analogRead(ldrpin);
  if (ldr < ldrthreshold){
    digitalWrite(warningled, HIGH); 
    bool isfriend = false;
    long gracetime = millis();

    while (millis() - gracetime < 4000) {    // waiting for four seconds
      if (digitalRead(buttonpin) == LOW) {
        isfriend = true;
        break; 
      }
    }

    if (isfriend){
      digitalWrite(warningled, LOW);
      delay(3000); //delay to allow the ppl to walk through the beam
    }
    else{

      Wire.beginTransmission(8); // we need to pass only the address of the slave , not the pins of led or buzzer
      Wire.write(1);
      Wire.endTransmission();
      delay(20000);
      Wire.beginTransmission(8); 
      Wire.write(1);
      Wire.endTransmission();
      digitalWrite(warningled, LOW);     
      
    }

  }
}