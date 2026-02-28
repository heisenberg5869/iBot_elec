// Task 2.0.2: Breathing LED using ESP32 LEDC peripheral
// Connect external LED (with resistor) to GPIO 2

#define LED_PIN     2
#define LEDC_CHANNEL    0
#define LEDC_FREQ_HZ    5000
#define LEDC_RESOLUTION 8     // 8-bit: duty cycle 0–255

void setup() {
  ledcSetup(LEDC_CHANNEL, LEDC_FREQ_HZ, LEDC_RESOLUTION);
  ledcAttachPin(LED_PIN, LEDC_CHANNEL);
}

void loop() {
  // Fade IN
  for (int duty = 0; duty <= 255; duty++) {
    ledcWrite(LEDC_CHANNEL, duty);
    delay(8);
  }
  // Fade OUT
  for (int duty = 255; duty >= 0; duty--) {
    ledcWrite(LEDC_CHANNEL, duty);
    delay(8);
  }
}