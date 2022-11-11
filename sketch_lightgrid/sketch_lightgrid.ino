#include "FastLED.h"

// FastLED vars
#define LED_COUNT 50
#define LED_DATA_PIN 6
CRGB leds[LED_COUNT];

void setup() {
    
    // Begin serial
    Serial.begin(9600);
    Serial.println("Loaded Lightgrid v1");

    // Setup FastLED
    pinMode(LED_DATA_PIN, OUTPUT);
    FastLED.addLeds<WS2811, LED_DATA_PIN, RGB>(leds, LED_COUNT);

}

int counter = 0;
float fadeAmt = 0.0;
void loop() {

  // Adjust fade
  float time = millis();
  float fadeAmt = (1 + sin(time / 1000.0)) / 2;

  // Position
  int drift = 5;
  float pos = fadeAmt * LED_COUNT;

  // Set all
  for (int i = 0 ; i < LED_COUNT ; i++) {

    // Set color
    leds[i].r = 255;
    leds[i].g = 0;
    leds[i].b = 0;
    if (i % 2 == 0) {
      leds[i].g = leds[i].r;
      leds[i].r = 0;
    }

    // Opacity based on position
    float opacity = max(0, min(1, 1 - abs(i - pos) / drift));
    leds[i].r *= opacity;
    leds[i].g *= opacity;
    leds[i].b *= opacity;

  }

    // Set all off
    // for (int i = 0 ; i < LED_COUNT ; i++) leds[i] = CRGB::Black;

    // // Set one LED on
    // counter++;
    // if (counter >= LED_COUNT) counter = 0;
    // leds[counter] = counter % 2 ? CRGB::Red : CRGB::Green;

    // Show it
    FastLED.show();
    delay(10);
    
}