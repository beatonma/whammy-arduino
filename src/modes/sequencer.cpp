#include "./sequencer.h"
#include "../../config.h"
#include "../pedal/pedal.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "./scales.h"
#include <stdlib.h>

const uint8_t SEQ_BUFFER_SIZE = 64;
const uint8_t SEQ_NULL = 0;
const uint8_t SEQ_SQUARE = 1;
const uint8_t SEQ_MOTP = 2;
const uint8_t SEQ_OCTAVES_UP = 3;
const uint8_t SEQ_RANDOM = 4;

const uint8_t SEQUENCES[] = {
  SEQ_SQUARE,
  SEQ_MOTP,
  SEQ_OCTAVES_UP,
  SEQ_RANDOM,
};
const uint8_t NUM_SEQUENCES = sizeof(SEQUENCES);

namespace Sequencer {
  namespace {
    uint8_t stepIndex = 0;
    uint8_t sequence = SEQ_NULL;
    uint8_t sequenceIndex = 0;

    double positionBuffer[SEQ_BUFFER_SIZE];
    uint8_t patchBuffer[SEQ_BUFFER_SIZE];
    uint8_t sequenceLength = SEQ_BUFFER_SIZE;

    void initRandom() {
      sequenceLength = rand() % SEQ_BUFFER_SIZE;
      for (int i = 0; i < sequenceLength; i++) {
        positionBuffer[i] = Scale::anyNote();
      }
    }

    void initSquare() {
      sequenceLength = 2;
      for (int i = 0; i < sequenceLength; i++) {
        if (i % 2 == 0) {
          positionBuffer[i] = 0;
        }
        else {
          positionBuffer[i] = Pedal::getMaxPosition();
        }
      }
    }

    void initMotp() {
      sequenceLength = SEQ_BUFFER_SIZE;
      Tempo::setTempo(125.0);
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

      // Same again
      patchBuffer[16] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[17] = PATCH_OFF;
      patchBuffer[18] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[19] = PATCH_OFF;
      patchBuffer[20] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[21] = PATCH_OFF;
      patchBuffer[22] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[23] = PATCH_OFF;
      patchBuffer[24] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[25] = PATCH_OFF;
      patchBuffer[26] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[27] = PATCH_OFF;
      patchBuffer[28] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[29] = PATCH_OFF;
      patchBuffer[30] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[31] = PATCH_OFF;

      // Same again
      patchBuffer[32] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[33] = PATCH_OFF;
      patchBuffer[34] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[35] = PATCH_OFF;
      patchBuffer[36] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[37] = PATCH_OFF;
      patchBuffer[38] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[39] = PATCH_OFF;
      patchBuffer[40] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[41] = PATCH_OFF;
      patchBuffer[42] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[43] = PATCH_OFF;
      patchBuffer[44] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[45] = PATCH_OFF;
      patchBuffer[46] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[47] = PATCH_OFF;

      // Different
      patchBuffer[48] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[49] = PATCH_OFF;
      patchBuffer[50] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[51] = PATCH_OFF;
      patchBuffer[52] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[53] = PATCH_OFF;
      patchBuffer[54] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[55] = PATCH_OFF;
      patchBuffer[56] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[57] = PATCH_OFF;
      patchBuffer[58] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[59] = PATCH_OFF;
      patchBuffer[60] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[61] = PATCH_OFF;
      patchBuffer[62] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[63] = PATCH_OFF;
    }

    void initOctavesUp() {
      sequenceLength = 5;
      Pedal::setPosition(127.0);
      patchBuffer[0] = PATCH_WHAMMY_MINUS_TWO;
      patchBuffer[1] = PATCH_WHAMMY_MINUS_ONE;
      patchBuffer[2] = PATCH_OFF;
      patchBuffer[3] = PATCH_WHAMMY_PLUS_ONE;
      patchBuffer[4] = PATCH_WHAMMY_PLUS_TWO;
    }

    void stepPosition() {
      Pedal::setPosition(positionBuffer[stepIndex]);
    }

    void stepPatch() {
      Pedal::setPatch(patchBuffer[stepIndex]);
    }

    void nextStep() {
      stepIndex = (stepIndex + 1) % sequenceLength;
    }

    void step(bool position, bool patch) {
      Tempo::onPulse(&nextStep, 1.0);  // 4 sequencer steps per quarter.

      if (position) {
        stepPosition();
      }
      if (patch) {
        stepPatch();
      }
    }
  }

  void square() {
    step(true, false);
  }

  void motp() {
    Pedal::setPosition(127.0);
    step(false, true);
  }

  void octavesUp() {
    Pedal::setPosition(127.0);
    step(false, true);
  }

  void random() {
    step(true, false);
  }

  void step() {
    if (sequence == SEQ_NULL) {
      sequence = SEQ_SQUARE;
      initSquare();
    }

    switch (sequence) {
      case SEQ_SQUARE:
        square();
        break;

      case SEQ_MOTP:
        motp();
        break;

      case SEQ_OCTAVES_UP:
        octavesUp();
        break;
      
      case SEQ_RANDOM:
        random();
        break;
    }
  }

  void next() {
    sequenceIndex = (sequenceIndex + 1) % NUM_SEQUENCES;
    sequence = SEQUENCES[sequenceIndex];
    reset();
    Tempo::reset();

    switch (sequence) {
      case SEQ_SQUARE:
        initSquare();
        break;
      
      case SEQ_MOTP:
        initMotp();
        break;
      
      case SEQ_OCTAVES_UP:
        initOctavesUp();
        break;
      
      case SEQ_RANDOM:
        initRandom();
        break;
    }
  }

  void reset() {
    stepIndex = 0;
  }
}
