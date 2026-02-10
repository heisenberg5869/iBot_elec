#include <LiquidCrystal.h>

// RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int backlightPin =9;

void setup() {
  pinMode(backlightPin, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  analogWrite(backlightPin, 100);
  lcd.setCursor(0, 0);
  lcd.print("Hello world");
  lcd.setCursor(0, 1);
  lcd.print("Sarrveshwar T");
}