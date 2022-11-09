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
void loop() {

    // Set all off
    for (int i = 0 ; i < LED_COUNT ; i++) leds[i] = CRGB::Black;

    // Set one LED on
    counter++;
    if (counter >= LED_COUNT) counter = 0;
    leds[counter] = counter % 2 ? CRGB::Red : CRGB::Green;

    // Show it
    FastLED.show();
    delay(10);
    
}