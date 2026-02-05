
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2 
#define DHTTYPE    DHT11     

DHT dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  dht.begin();
  delayMS =1000;
}

void loop() {
  delay(delayMS);
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  if (isnan(t)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(t);
    Serial.println(F("°C"));
  }
  
  if (isnan(h)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println(F("%"));
  }
}