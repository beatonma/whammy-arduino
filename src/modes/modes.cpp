#include <stdint.h>
#include <stdlib.h>
#include "../../config.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../modes/modes.h"
#include "../pedal/pedal.h"
#include "./chaos.h"
#include "./sequencer.h"
#include "./scales.h"
#include "./waves.h"
#include "../led/led.h"

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
          LED::green();
          Chaos::randomPosition();
          break;

        case MODE_SCALE:
          LED::magenta();
          Scale::run();
          break;

        case MODE_RANDOM_POSITION_STUTTER:
          LED::green();
          Chaos::randomPositionWithStutter();
          break;

        case MODE_SEQUENCER:
          LED::red();
          Sequencer::step();
          break;
        
        case MODE_RANDOM_PATCH_AND_POSITION:
          LED::green();
          Chaos::randomPatchAndPosition();
          break;
        
        case MODE_TRUE_CHAOS:
          LED::green();
          Tempo::onPulse(&runAny, 1.0);
          break;

        case MODE_WAVES:
          LED::blue();
          Waves::run();
          break;
      }
    }

  void runAny() {
    run(MODES[rand() % (NUM_MODES - 1)]); // Any mode except TRUE_CHAOS
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