#include <Arduino.h>
#include "../../config.h"
#include "./led.h"

namespace LED {
  namespace {
    int currentBrightness = 0;
  }

  void setBrightness(uint8_t brightness) {
    currentBrightness = max(0, min(brightness, MAX_BRIGHTNESS));
    analogWrite(PIN_LED, currentBrightness);
  }

  void set(bool _on) {
    if (_on) {
      on();
    }
    else {
      off();
    }
  }

  void off() {
    setBrightness(0);
  }

  void on() {
    setBrightness(MAX_BRIGHTNESS);
  }

  void fade() {
    fadeBy(10);
  }

  void fadeBy(int amount) {
    setBrightness(currentBrightness - amount);
  }
}