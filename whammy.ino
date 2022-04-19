#include <Arduino.h>
#include "./config.h"
#include "./src/led/led.h"
#include "./src/modes/modes.h"
#include "./src/pedal/pedal.h"
#include "./src/tempo/tempo.h"
#include "./src/frame/frame.h"
#include "./src/inputs.h"


OnOffButtonHandler _onOffButton(PIN_BUTTON_ON_OFF);
ModeButtonHandler _modeButton(PIN_BUTTON_MODE);
ModifierButtonHandler _modifierButton(PIN_BUTTON_MODIFIER);
TempoPotHandler _tempoPot(PIN_POT_TEMPO);


bool active = true;

void setup() {
  Serial.begin(31250);

  pinMode(PIN_LED, OUTPUT);
  LED::ledOn();
  setupInputHandlers();

  applyState();
}

void loop() {
  Frame::setTimestamp(millis());
  updateInputHandlers();

  if (active) {
    runMode();
    applyState();
  }
}

void applyState() {
  Pedal::apply();
  LED::setLedBrightness(Pedal::getPosition());
}

void setActive(bool _active) {
  active = _active;

  if (!_active) {
    LED::ledOff();
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

void OnOffButtonHandler::onButtonPressed(void) {
  setActive(!active);
}

void TempoPotHandler::onProgressChanged(double progress) {
  if (_modifierButton.isDown()) {
    Pedal::setMaxPosition(progress * 127.0);
  }
  else {
    Tempo::setTempo(MIN_TEMPO + (progress * TEMPO_RANGE));
  }
}

void ModifierButtonHandler::onButtonPressed(void) {

}

void OnOffButtonHandler::onButtonDown(void) {
  
}

void OnOffButtonHandler::onButtonUp(void) {
  
}

void ModeButtonHandler::onButtonDown(void) {
  if (_modifierButton.isDown()) {
    previousMode();
  }
  else {
    nextMode();
  }
}

void ModeButtonHandler::onButtonPressed(void) {
  
}

void ModeButtonHandler::onButtonUp(void) {
  
}

void ModifierButtonHandler::onButtonDown(void) {
  
}

void ModifierButtonHandler::onButtonUp(void) {
  
}
