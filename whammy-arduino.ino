#include <Arduino.h>
#include <EEPROM.h>
#include "./config.h"
#include "./src/led/led.h"
#include "./src/modes/modes.h"
#include "./src/pedal/pedal.h"
#include "./src/tempo/tempo.h"
#include "./src/frame/frame.h"
#include "./src/inputs.h"
#include "./src/modes/scales.h"
#include "./src/modes/sequencer.h"
#include "./src/modes/waves.h"

const uint8_t EEPROM_MOMENTARY = 0;

OnOffButtonHandler _onOffButton(PIN_BUTTON_ON_OFF);
ModeButtonHandler _modeButton(PIN_BUTTON_MODE);
ModifierButtonHandler _modifierButton(PIN_BUTTON_MODIFIER);
TempoPotHandler _tempoPot(PIN_POT_TEMPO);


/**
 * If true, the pedal is only active while the button is held.
 * If false, on/off button works as a toggle.
 */
bool momentary = true;

void setup() {
  momentary = EEPROM.read(EEPROM_MOMENTARY);

  Serial.begin(31250);
  LED::setup();
  setupInputHandlers();
  flashLED();

  applyState();
}

void loop() {
  Frame::setTimestamp(millis());
  updateInputHandlers();

  Mode::run();

  if (Pedal::getActive() || Mode::isContinuous()) {
    applyState();
  }
}

void flashLED() {
  LED::white();
  for (int i = 0; i < 3; i++) {
    LED::on();
    delay(100);
    LED::off();
    delay(100);
  }
}

void applyState() {
  Pedal::apply();
  LED::setBrightness(Pedal::getPosition());
}

void setActive(bool _active) {
  Pedal::setActive(_active);

  if (_active) {
    if (!Mode::isContinuous()) {
      Pedal::on();
    }
    reset();
    applyState();
  }

  else {
    if (!Mode::isContinuous()) {
      Pedal::off();
      LED::off();
    }
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
    EEPROM.update(EEPROM_MOMENTARY, momentary);
    setActive(false);
    flashLED();
  }
  else {
    setActive(!Pedal::getActive());
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
  Scale::next();
  Sequencer::next();
  Waves::next();
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
