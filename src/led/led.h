#ifndef H_LED
#define H_LED

namespace LED {
  void setup();
  void setBrightness(uint8_t brightness);
  void set(bool on);
  void on();
  void off();
  void fade();
  void fadeBy(int amount);

  void red();
  void green();
  void blue();
  void yellow();
  void cyan();
  void magenta();
  void white();
}

#endif
