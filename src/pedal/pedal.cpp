#include <Arduino.h>
#include "./pedal.h"
#include "./patches.h"
#include "./midi.h"

namespace Pedal {
  namespace {
    int currentPatch = 3;
    double currentPosition = 0;
    double maxPosition = 127.0;

    void sendPatch() {
      Serial.write(COMMAND_PATCH_CHANGE);
      Serial.write(PATCHES[currentPatch]);
    }

    void sendPosition() {
      Serial.write(COMMAND_CC_CHANGE);
      Serial.write(CC_PEDAL_POSITION);
      Serial.write((int) currentPosition);
    }
  }

  void setPatch(int patchID) {
    currentPatch = patchID;
  }

  void setPosition(double position) {
    currentPosition = position;
  }

  void setMaxPosition(double max) {
    maxPosition = max;
  }

  void apply() {
    if (currentPatch != PATCH_NULL) {
      sendPatch();
    }
    if (currentPosition != POSITION_NULL) {
      sendPosition();
    }
  }

  int getPatch() {
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