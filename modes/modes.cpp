#include "../config.h"

uint8_t _currentModeID = 0;
uint8_t _currentModeIndex = 0;

void runMode(uint8_t* state) {
  switch (_currentModeID) {
    case MODE_RANDOM_POSITION:
      break;
    case MODE_SAW_UP:
      sawUp(state);
      break;
    case MODE_SAW_DOWN:
      sawDown(state);
      break;
    case MODE_TRIANGLE:
      triangle(state);
      break;
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
