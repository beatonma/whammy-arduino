#include <stdint.h>
#include "../../config.h"
#include "../frame/frame.h"
#include "../modes/modes.h"
#include "./sawtooth.h"
#include "./triangle.h"

namespace {
  uint8_t currentModeID = MODE_SAW_UP;
  uint8_t currentModeIndex = 0;
}

void runMode() {
  switch (currentModeID) {
    // case MODERANDOMPOSITION:
    //   break;

    case MODE_SAW_UP:
      Sawtooth::sawUp();
      break;

    case MODE_SAW_DOWN:
      Sawtooth::sawDown();
      break;

    case MODE_TRIANGLE:
      Triangle::triangle();
      break;

    // case MODESQUARE:
    //   square();
    //   break;
    // case MODECHAOS:
    //   chaos();
    //   break;
  }
}

void nextMode() {
  currentModeIndex = (currentModeIndex + 1) % NUM_MODES;
  currentModeID = MODES[currentModeIndex];
}
