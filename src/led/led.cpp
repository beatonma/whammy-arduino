#include <Arduino.h>
#include "../../config.h"
#include "./led.h"

namespace LED {
  namespace {
    int currentBrightness = MAX_BRIGHTNESS;
    double _red = 0.0;
    double _green = 0.0;
    double _blue = 0.0;

    void setRgb(double r, double g, double b) {
      _red = r;
      _green = g;
      _blue = b;
    }

    double normalize(int value) {
      return (double) value / 255.0;
    }

    void write() {
      const double brightness = normalize(currentBrightness);
      analogWrite(PIN_LED_RED, _red * brightness);
      analogWrite(PIN_LED_GREEN, _green * brightness);
      analogWrite(PIN_LED_BLUE, _blue * brightness);
    }

    void flash() {
      on();
      write();
      delay(200);
      off();
    }
  }

  void setup() {
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);

    red();
    flash();

    green();
    flash();

    blue();
    flash();
  }

  void setBrightness(uint8_t brightness) {
    currentBrightness = max(0, min(brightness, MAX_BRIGHTNESS));
    write();
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

  void red() {
    setRgb(255.0, 0.0, 0.0);

  }
  void green() {
    setRgb(0.0, 255.0, 0.0);
  }

  void blue() {
    setRgb(0.0, 0.0, 255.0);
  }

  void yellow() {
    setRgb(255.0, 255.0, 0.0);
  }

  void cyan() {
    setRgb(0.0, 255.0, 255.0);
  }

  void magenta() {
    setRgb(255.0, 0.0, 255.0);
  }

  void white() {
    setRgb(255.0, 255.0, 255.0);
  }
}