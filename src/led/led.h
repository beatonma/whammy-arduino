#ifndef H_LED
#define H_LED

namespace LED {
  void setBrightness(uint8_t brightness);
  void set(bool on);
  void on();
  void off();
  void fade();
  void fadeBy(int amount);
}

#endif
