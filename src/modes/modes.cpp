#include <stdint.h>
#include "../../config.h"
#include "../frame/frame.h"
#include "../modes/modes.h"
#include "./sawtooth.h"

namespace {
  uint8_t _currentModeID = MODE_SAW_UP;
  uint8_t _currentModeIndex = 0;
}

void runMode() {
  switch (_currentModeID) {
    // case MODE_RANDOM_POSITION:
    //   break;

    case MODE_SAW_UP:
      Sawtooth::sawUp();
      break;

    case MODE_SAW_DOWN:
      Sawtooth::sawDown();
      break;

    // case MODE_TRIANGLE:
    //   triangle(state);
    //   break;
    // case MODE_SQUARE:
    //   square();
    //   break;
    // case MODE_CHAOS:
    //   chaos();
    //   break;
  }
}

void nextMode() {
  _currentModeIndex = (_currentModeIndex + 1) % NUM_MODES;
  _currentModeID = MODES[_currentModeIndex];
}
