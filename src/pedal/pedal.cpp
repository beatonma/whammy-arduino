#include <Arduino.h>
#include "./pedal.h"
#include "./patches.h"
#include "./midi.h"

namespace {
  int currentPatch = 0;
  int currentPosition = 0;

  void sendPatch() {
    Serial.write(COMMAND_PATCH_CHANGE);
    Serial.write(PATCHES[currentPatch]);
  }

  void sendPosition() {
    Serial.write(COMMAND_CC_CHANGE);
    Serial.write(CC_PEDAL_POSITION);
    Serial.write(currentPosition);
  }
}

void Pedal::setPatch(int patchID) {
  currentPatch = patchID;
  // Serial.write(COMMAND_PATCH_CHANGE);
  // Serial.write(PATCHES[patchID]);
}

void Pedal::setPosition(int position) {
  currentPosition = position;
  Serial.write(COMMAND_CC_CHANGE);
  Serial.write(CC_PEDAL_POSITION);
  Serial.write(position);
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

int Pedal::getPosition() {
  return currentPosition;
}