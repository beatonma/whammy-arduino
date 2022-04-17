#ifndef H_LED
#define H_LED

namespace LED {
  void setLedBrightness(uint8_t brightness);
  void setLed(boolean on);
  void ledOn();
  void ledOff();
  void fade();
  void fadeBy(int amount);
}

#endif
