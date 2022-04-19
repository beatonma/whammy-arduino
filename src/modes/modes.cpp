#include <stdint.h>
#include "../../config.h"
#include "../frame/frame.h"
#include "../modes/modes.h"
#include "./chaos.h"
#include "./sawtooth.h"
#include "./triangle.h"
#include "./sequencer.h"

namespace {
  uint8_t currentModeIndex = 0;
  uint8_t currentModeID = MODES[currentModeIndex];
}

void runMode() {
  switch (currentModeID) {
    case MODE_SAW_UP:
      Sawtooth::sawUp();
      break;

    case MODE_SAW_DOWN:
      Sawtooth::sawDown();
      break;

    case MODE_TRIANGLE:
      Triangle::triangle();
      break;

    case MODE_SQUARE:
      Sequencer::square();
      break;

    case MODE_CHAOS:
      Chaos::randomPosition();
      break;
  }
}

void nextMode() {
  currentModeIndex = (currentModeIndex + 1) % NUM_MODES;
  currentModeID = MODES[currentModeIndex];
}
