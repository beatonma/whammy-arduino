#include <stdint.h>
#include <stdlib.h>
#include "../../config.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../modes/modes.h"
#include "../pedal/pedal.h"
#include "./chaos.h"
#include "./sawtooth.h"
#include "./continuous.h"
#include "./sequencer.h"

namespace Mode {
  namespace {
    uint8_t currentModeIndex = 0;
    uint8_t currentModeID = MODES[currentModeIndex];
  }

  void run() {
    run(currentModeID);
  }

  void run(uint8_t modeID) {
      switch (modeID) {
        case MODE_RANDOM_POSITION:
          Chaos::randomPosition();
          break;

        case MODE_SAW_UP:
          Sawtooth::sawUp();
          break;

        case MODE_SAW_DOWN:
          Sawtooth::sawDown();
          break;

        case MODE_TRIANGLE:
          Continuous::triangle();
          break;
        
        case MODE_SINE:
          Continuous::sine();
          break;

        case MODE_SQUARE:
          Sequencer::square();
          break;
        
        case MODE_RANDOM_PATCH_AND_POSITION:
          Chaos::randomPatchAndPosition();
          break;

        case MODE_MOTP:
          Sequencer::motp();
          break;
        
        case MODE_TRUE_CHAOS:
          Tempo::onPulse(&runAny, 1.0);
          break;
      }
    }

  void runAny() {
    run(MODES[rand() % (NUM_MODES - 2)]); // Any mode except MOTP
  }

  void next() {
    Pedal::setPatch(PATCH_NULL);
    currentModeIndex = (currentModeIndex + 1) % NUM_MODES;
    currentModeID = MODES[currentModeIndex];
  }

  void previous() {
    Pedal::setPatch(PATCH_NULL);
    currentModeIndex = (NUM_MODES + currentModeIndex - 1) % NUM_MODES;
    currentModeID = MODES[currentModeIndex];
  }
}