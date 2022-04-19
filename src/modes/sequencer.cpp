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
    unsigned long lastStep = 0;
    uint8_t index = 0;

    uint8_t sequence = SEQ_NULL;
    double positionBuffer[SEQ_BUFFER_SIZE] = {
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
    };
    double patchBuffer[SEQ_BUFFER_SIZE] = {
      DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH,
      DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH,
      DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH,
      DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH, DEFAULT_PATCH,
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
      // TODO
    }

    void stepPosition() {
      Pedal::setPosition(positionBuffer[index]);
    }

    void stepPatch() {
      Pedal::setPatch(patchBuffer[index]);
    }

    void step(bool position, bool patch) {
      if (Frame::getTime() - lastStep >= Tempo::getPulseMillis() / 4.0) {
        // 4 sequencer steps per quarter.
        index = (index + 1) % SEQ_BUFFER_SIZE;
        lastStep = Frame::getTime();
      }

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

    step(true, true);
  }
}

// const uint8_t SEQUENCE_LENGTH = 16;
// uint8_t patchSequence[SEQUENCE_LENGTH] = {
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
//   DEFAULT_PATCH,
// };

// uint8_t positionSequence[SEQUENCE_LENGTH] = {
//   0,
//   127,
//   0,
//   127,
//   0,
//   127,
//   0,
//   127,
//   0,
//   127,
//   0,
//   127,
//   0,
//   127,
//   0,
//   127,
// };
// uint8_t sequenceIndex = 0;

// // void sequencePosition(byte positions[]) {
// //   setPosition(positions[sequenceIndex]);
// //   sequenceIndex = (sequenceIndex + 1) % SEQUENCE_LENGTH;
// // }

// // void mapOfTheProblematique() {
// //   // TODO
// // }

// // void square() {
// //   sequencePosition(positionSequence);
// //   scheduleNext(500);
// // }
