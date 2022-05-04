#include <Arduino.h>
#include "./pedal.h"
#include "./patches.h"
#include "./midi.h"
#include "../../config.h"

namespace Pedal {
  namespace {
    uint8_t activePatch = DEFAULT_PATCH;
    uint8_t currentPatch = PATCH_NULL;
    double currentPosition = 0.0;
    double maxPosition = 127.0;
    uint8_t isActive = false;

    void sendPatch() {
      Serial.write(COMMAND_PATCH_CHANGE);
      Serial.write(currentPatch);
    }

    void sendPosition() {
      Serial.write(COMMAND_CC_CHANGE);
      Serial.write(CC_PEDAL_POSITION);
      Serial.write((int) currentPosition);
    }
  }

  void setPatch(uint8_t patchID) {
    if (patchID != PATCH_OFF && patchID != PATCH_NULL) {
      activePatch = patchID;
    }
    currentPatch = patchID;
  }

  void on() {
    setPatch(activePatch);;
  }

  void coerceOn() {
    if (currentPatch == PATCH_OFF) {
      on();
    }
  }

  void off() {
    setPatch(PATCH_OFF);
    apply();
  }

  void setPosition(double position) {
    currentPosition = position;
  }

  void setMaxPosition(double max) {
    maxPosition = max;
  }

  void setActive(bool active) {
    isActive = active;
  }

  bool getActive() {
    return isActive;
  }

  void apply() {
    if (currentPatch != PATCH_NULL) {
      sendPatch();
    }
    if (currentPosition != POSITION_NULL) {
      sendPosition();
    }
  }

  uint8_t getPatch() {
    return currentPatch;
  }

  double getPosition() {
    return currentPosition;
  }

  double getMaxPosition() {
    return maxPosition;
  }

  uint8_t anyPatch() {
    return PATCHES[rand() % NUM_PATCHES];
  }

  double anyPosition() {
    return rand() % (int) getMaxPosition();
  }

  double anyQuantizedPosition() {
    return QUANTIZED_POSITIONS[rand() % NUM_QUANTIZED_POSITIONS];
  }
}