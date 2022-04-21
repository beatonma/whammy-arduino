#include <Arduino.h>
#include "./config.h"
#include "./src/led/led.h"
#include "./src/modes/modes.h"
#include "./src/pedal/pedal.h"
#include "./src/tempo/tempo.h"
#include "./src/frame/frame.h"
#include "./src/inputs.h"
#include "./src/modes/scales.h"
#include "./src/modes/sequencer.h"


OnOffButtonHandler _onOffButton(PIN_BUTTON_ON_OFF);
ModeButtonHandler _modeButton(PIN_BUTTON_MODE);
ModifierButtonHandler _modifierButton(PIN_BUTTON_MODIFIER);
TempoPotHandler _tempoPot(PIN_POT_TEMPO);


/**
 * If true, the pedal is only active while the button is held.
 * If false, on/off button works as a toggle.
 */
bool momentary = true;

bool active = !momentary;

void setup() {
  Serial.begin(31250);

  pinMode(PIN_LED, OUTPUT);
  LED::on();
  setupInputHandlers();
  delay(100);
  LED::off();

  applyState();
}

void loop() {
  Frame::setTimestamp(millis());
  updateInputHandlers();

  if (active) {
    Mode::run();
    applyState();
  }
}

void applyState() {
  Pedal::apply();
  LED::setBrightness(Pedal::getPosition());
}

void setActive(bool _active) {
  active = _active;

  if (active) {
    Pedal::setPatch(DEFAULT_PATCH);
    reset();
    applyState();
  }

  else {
    Pedal::off();
    LED::off();
  }
}

void reset() {
  Tempo::reset();
  Sequencer::reset();
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
  if (_modifierButton.isDown()) {
    momentary = !momentary;
    setActive(false);
  }
  else {
    setActive(!active);
  }
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
  Scale::nextScale();
  Sequencer::next();
}

void OnOffButtonHandler::onButtonDown(void) {
  if (momentary) {
    setActive(true);
  }
}

void OnOffButtonHandler::onButtonUp(void) {
  if (momentary) {
    setActive(false);
  }
}

void ModeButtonHandler::onButtonDown(void) {
  if (_modifierButton.isDown()) {
    Mode::previous();
  }
  else {
    Mode::next();
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
