#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define AUDIO_PIN A0

int centerLine = SCREEN_HEIGHT / 2;
int barWidth = 10;

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    while (true); 
  }
  display.clearDisplay();
  display.display();
}



void loop() {
  int audioValue = analogRead(AUDIO_PIN);
  int deviation = abs(audioValue - 512);
  int barHeight = map(deviation, 0, 512, 0, centerLine);

  barHeight = constrain(barHeight, 0, centerLine);
  display.clearDisplay();
  int x = SCREEN_WIDTH / 2 - barWidth / 2;
  display.fillRect(x,centerLine - barHeight,barWidth,barHeight,SSD1306_WHITE );
  display.fillRect(x,centerLine,barWidth,barHeight,SSD1306_WHITE);

  display.display();
}

