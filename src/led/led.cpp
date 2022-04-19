#include <Arduino.h>
#include "../../config.h"
#include "./led.h"

// using namespace LED;

namespace {
  int _currentBrightness = 0;
}

void LED::setLedBrightness(uint8_t brightness) {
  _currentBrightness = max(0, min(brightness, MAX_BRIGHTNESS));
  analogWrite(PIN_LED, _currentBrightness);
}

void LED::setLed(bool on) {
  if (on) {
    ledOn();
  }
  else {
    ledOff();
  }
}

void LED::ledOff() {
  setLedBrightness(0);
}

void LED::ledOn() {
  setLedBrightness(MAX_BRIGHTNESS);
}

void LED::fade() {
  fadeBy(10);
}

void LED::fadeBy(int amount) {
  setLedBrightness(_currentBrightness - amount);
}
