#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel *_pixels;
#define NP_PIN 3

void setup() {
  // put your setup code here, to run once:
  _pixels = new Adafruit_NeoPixel(1, NP_PIN, NEO_GRB + NEO_KHZ800);
  _pixels->begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  _pixels->clear(); // Set all pixel colors to 'off'
  _pixels->setPixelColor(0, _pixels->Color(0, 150, 0)); // green
  _pixels->show();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
