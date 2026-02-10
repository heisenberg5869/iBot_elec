#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int grid = 8;
int posX = 8; 
int posY = 4; 


const int btnUp = 7;
const int btnDown = 6;
const int btnLeft = 5;
const int btnRight = 4;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnLeft, INPUT_PULLUP);
  pinMode(btnRight, INPUT_PULLUP);

  display.clearDisplay();
}

void loop() {
  if (digitalRead(btnUp) == LOW)    posY--;
  if (digitalRead(btnDown) == LOW)  posY++;
  if (digitalRead(btnLeft) == LOW)  posX--;
  if (digitalRead(btnRight) == LOW) posX++;

  if (posX < 0)  posX = 15;
  if (posX > 15) posX = 0; 
  if (posY < 0)  posY = 7;  
  if (posY > 7)  posY = 0;  


  display.clearDisplay();

  int pixelX = posX * grid;
  int pixelY = posY * grid;
  
  display.fillRect(pixelX, pixelY, grid, grid, WHITE);
  display.display();

  delay(100); 
}