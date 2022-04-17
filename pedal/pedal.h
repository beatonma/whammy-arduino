#include "./midi.h"
#include "./patches.h"

void setPatch(uint8_t patchID) {
  Serial.write(COMMAND_PATCH_CHANGE);
  Serial.write(PATCHES[patchID]);
}

void setPosition(uint8_t position) {
  Serial.write(COMMAND_CC_CHANGE);
  Serial.write(CC_PEDAL_POSITION);
  Serial.write(position);
}
