#include "./sequencer.h"
#include "../../config.h"
#include "../pedal/pedal.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"

#define SEQ_BUFFER_SIZE 16
#define SEQ_NULL 0
#define SEQ_SQUARE 1
#define SEQ_MOTP 2

namespace Sequencer {
  namespace {
    uint8_t index = 0;

    uint8_t sequence = SEQ_NULL;
    double positionBuffer[SEQ_BUFFER_SIZE] = {
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
    };
    uint8_t patchBuffer[SEQ_BUFFER_SIZE] = {
      Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(),
      Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(),
      Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(),
      Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(), Patch::anyPatch(),
    };

    void initSquare() {
      for (int i = 0; i < SEQ_BUFFER_SIZE; i++) {
        if (i % 2 == 0) {
          positionBuffer[i] = 0;
        }
        else {
          positionBuffer[i] = Pedal::getMaxPosition();
        }
      }
    }

    void initMotp() {
      Tempo::setTempo(121.0);
      Pedal::setPosition(127.0);

      patchBuffer[0] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[1] = PATCH_OFF;
      patchBuffer[2] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[3] = PATCH_OFF;
      patchBuffer[4] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[5] = PATCH_OFF;
      patchBuffer[6] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[7] = PATCH_OFF;
      patchBuffer[8] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[9] = PATCH_OFF;
      patchBuffer[10] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[11] = PATCH_OFF;
      patchBuffer[12] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[13] = PATCH_OFF;
      patchBuffer[14] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[15] = PATCH_OFF;
    }

    void stepPosition() {
      Pedal::setPosition(positionBuffer[index]);
    }

    void stepPatch() {
      Pedal::setPatch(patchBuffer[index]);
    }

    void nextStep() {
      index = (index + 1) % SEQ_BUFFER_SIZE;
    }


    void step(bool position, bool patch) {
      Tempo::onPulse(&nextStep, 0.25);  // 4 sequencer steps per quarter.

      if (position) {
        stepPosition();
      }
      if (patch) {
        stepPatch();
      }
    }
  }

  void square() {
    if (sequence != SEQ_SQUARE) {
      sequence = SEQ_SQUARE;
      initSquare();
    }

    step(true, false);
  }

  void motp() {
    if (sequence != SEQ_MOTP) {
      sequence = SEQ_MOTP;
      initMotp();
    }

    step(false, true);
  }
}
