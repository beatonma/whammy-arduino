#include <Arduino.h>
#include "./config.h"
#include "./led/led.h"
#include "./led/led.cpp"
#include "./modes/modes.h"
#include "./modes/modes.cpp"
#include "./pedal/pedal.h"
#include "./inputs.h"


OnOffButtonHandler _onOffButton(PIN_BUTTON_ON_OFF);
ModeButtonHandler _modeButton(PIN_BUTTON_MODE);
ModifierButtonHandler _modifierButton(PIN_BUTTON_MODIFIER);
TempoPotHandler _tempoPot(PIN_POT_TEMPO);


boolean active = true;
uint8_t currentState[2] = {DEFAULT_PATCH, DEFAULT_POSITION};
int _delay = 100;

void setup() {
  Serial.begin(31250);

  pinMode(PIN_LED, OUTPUT);
  LED::ledOn();
  setupInputHandlers();
  for (int i = 0; i < 3; i++) {
    LED::ledOff();
    delay(100);
    LED::ledOn();
  }

  LED::setLed(active);

  if (active) {
    applyState();
  }
}

void loop() {
  updateInputHandlers();

  // LED::fade();

  if (active) {
    runMode(currentState);

    applyState();
    delay(_delay);
  }
}

void setupInputHandlers() {
  _onOffButton.setup();
  _modeButton.setup();
  _modifierButton.setup();
  _tempoPot.setup();
}

void updateInputHandlers() {
  _onOffButton.update();
  _modeButton.update();
  _modifierButton.update();
  _tempoPot.update();
}

void applyState() {
  setPatch(currentState[0]);
  setPosition(currentState[1]);
}

void setActive(boolean _active) {
  active = _active;
  LED::setLed(active);
}

void OnOffButtonHandler::onButtonDown(void) {
  // active = !active;
  // setLed(active);
}

void OnOffButtonHandler::onButtonPressed(void) {
  setActive(!active);
  // LED::setLed(active);
}

void OnOffButtonHandler::onButtonUp(void) {
  // active = !active;
  // setLed(active);
}

void ModeButtonHandler::onButtonDown(void) {
  nextMode();
  // active = !active;
  // setLed(active);
}

void ModeButtonHandler::onButtonPressed(void) {
  // nextMode();
  // LED::setLed(active);
}

void ModeButtonHandler::onButtonUp(void) {
  // active = !active;
  // setLed(active);
}

void ModifierButtonHandler::onButtonDown(void) {
  // active = !active;
  // setLed(active);
}

void ModifierButtonHandler::onButtonPressed(void) {
  setActive(!active);
  // LED::setLed(active);
}

void ModifierButtonHandler::onButtonUp(void) {
  // active = !active;
  // setLed(active);
}

void TempoPotHandler::onValueChanged(int value) {
  _delay = (int) ((value / 1023.0) * 500);
}
