#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define ANALOG_PIN A0
#define LED_PIN 4
#define RELAY_PIN 13

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);

  strip.begin();
  strip.setBrightness(100);
  strip.setPixelColor(0, strip.Color(0, 0, 255));
  strip.show();
}

void loop() {
  int A = analogRead(ANALOG_PIN);
  Serial.println(A);// Display serial results in serial monitor.
  if (A > 800 ) {   // 800 seems to be the appropriate cutoff for sensing DipJar led light output
    // Active state
    strip.setPixelColor(0, strip.Color(0, 255, 0));
    strip.show();

    // Relay burst pattern
    digitalWrite(RELAY_PIN, HIGH);
    delay(600);
    digitalWrite(RELAY_PIN, LOW);

    delay(300);

    digitalWrite(RELAY_PIN, HIGH);
    delay(300);
    digitalWrite(RELAY_PIN, LOW);

    delay(300);

    digitalWrite(RELAY_PIN, HIGH);
    delay(1200);
    digitalWrite(RELAY_PIN, LOW);

    // Stop listening for the next 5 seconds
    strip.setPixelColor(0, strip.Color(255, 0, 0));
    strip.show();
    digitalWrite(RELAY_PIN, LOW);
    delay(30000);
    
    // Return to ready state

    strip.setPixelColor(0, strip.Color(0, 0, 255));
    strip.show();
  }
}