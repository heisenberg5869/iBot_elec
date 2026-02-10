#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    while(true){

    }
  }


  display.clearDisplay();

  display.setTextSize(1);      
  display.setTextColor(WHITE); 
  display.setCursor(0, 0);     
  display.println("Hello World");

  display.drawRect(0, 20, 50, 30, WHITE);

  display.drawCircle(90, 35, 20, WHITE);

  display.display(); 
}

void loop() {
}