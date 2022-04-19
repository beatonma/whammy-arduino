#ifndef H_BUTTONS
#define H_BUTTONS

#include "./input/input-buttons.cpp"
#include "./input/input-potentiometer.cpp"

class OnOffButtonHandler: public AbstractButtonHandler {
  public:
  OnOffButtonHandler(uint8_t pin): AbstractButtonHandler(pin) {}

  void onButtonPressed(void);
  void onButtonDown(void);
  void onButtonUp(void);
};

class ModeButtonHandler: public AbstractButtonHandler {
  public:
  ModeButtonHandler(uint8_t pin): AbstractButtonHandler(pin) {}

  void onButtonPressed(void);
  void onButtonDown(void);
  void onButtonUp(void);
};

class ModifierButtonHandler: public AbstractButtonHandler {
  public:
  ModifierButtonHandler(uint8_t pin): AbstractButtonHandler(pin) {}

  void onButtonPressed(void);
  void onButtonDown(void);
  void onButtonUp(void);
};

class TempoPotHandler: public AbstractPotentiometerHandler {
  public:
  TempoPotHandler(uint8_t pin): AbstractPotentiometerHandler(pin) {}

  void onProgressChanged(double progress);
};

#endif
