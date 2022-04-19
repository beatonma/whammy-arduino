#include <Arduino.h>
#include "./pedal.h"
#include "./patches.h"
#include "./midi.h"

namespace {
  int currentPatch = 0;
  double currentPosition = 0;

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

void Pedal::setPatch(int patchID) {
  currentPatch = patchID;
}

void Pedal::setPosition(double position) {
  currentPosition = position;
}

void Pedal::apply() {
  if (currentPatch != PATCH_NULL) {
    sendPatch();
  }
  if (currentPosition != POSITION_NULL) {
    sendPosition();
  }
}

int Pedal::getPatch() {
  return currentPatch;
}

double Pedal::getPosition() {
  return currentPosition;
}