#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define ANALOG_PIN A0
#define LED_PIN 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
  int A = analogRead(ANALOG_PIN);
  Serial.println(A);// Display serial results in serial monitor.
  if (A > 400 ) {   // 800 seems to be the appropriate cutoff for sensing DipJar led light output
    // Activated state
    strip.setPixelColor(0, strip.Color(0, 255, 0));
    strip.show();
  }

  else {
    // Ready state
        strip.setPixelColor(0, strip.Color(0, 0, 255));
    strip.show();
  }
}