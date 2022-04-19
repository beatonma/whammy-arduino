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

// double currentState[2] = {DEFAULT_PATCH, DEFAULT_POSITION};

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

  applyState();
}

void loop() {
  Frame::setTimestamp(millis());
  updateInputHandlers();

  // LED::fade();

  if (active) {
    runMode();

    applyState();
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
  Pedal::apply();
  // Pedal::setPatch(currentState[0]);
  // Pedal::setPosition(currentState[1]);
  LED::setLedBrightness(Pedal::getPosition());
}

void setActive(bool _active) {
  active = _active;
  if (!_active) {
    LED::ledOff();
  }
}

void OnOffButtonHandler::onButtonDown(void) {
  
}

void OnOffButtonHandler::onButtonPressed(void) {
  setActive(!active);
}

void OnOffButtonHandler::onButtonUp(void) {
  
}

void ModeButtonHandler::onButtonDown(void) {
  nextMode();
}

void ModeButtonHandler::onButtonPressed(void) {
  
}

void ModeButtonHandler::onButtonUp(void) {
  
}

void ModifierButtonHandler::onButtonDown(void) {
  
}

void ModifierButtonHandler::onButtonPressed(void) {
  setActive(!active);
}

void ModifierButtonHandler::onButtonUp(void) {
  
}

void TempoPotHandler::onProgressChanged(double progress) {
  Tempo::setTempo(MIN_TEMPO + (int) (progress * (double) TEMPO_RANGE));
}
