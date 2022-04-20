#include <stdlib.h>
#include "./chaos.h"
#include "../pedal/pedal.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../pedal/pedal.h"

namespace Chaos {
  namespace {
    bool stutter = false;
    bool quantize = false;
    double stutterBuffer[] = {
      44, 0, 44, 0,
      44, 0, 44, 0,
      44, 0, 44, 0,
      44, 0, 44, 0,
    };
    const uint8_t bufferSize = 16;
    uint8_t stutterIndex = 0;
    double tempPosition;

    void doRandomPatchAndPosition() {
      Pedal::setPosition(Pedal::anyPosition());
      Pedal::setPatch(Pedal::anyPatch());
    }

    void doRandomPosition() {
      if (quantize) {
        Pedal::setPosition(Pedal::anyQuantizedPosition());
      }
      else {
        Pedal::setPosition(Pedal::anyPosition());
      }
    }

    void randomWrite() {
      if (rand() % 100 > 98) {
        tempPosition = Pedal::anyQuantizedPosition();
        for (int i = 0; i < bufferSize / 3; i++) {
          stutterBuffer[rand() % bufferSize] = tempPosition;
        }
      }
    }

    void readFromBuffer() {
      Pedal::setPosition(stutterBuffer[stutterIndex]);
    }

    void incrementBufferIndex() {
      stutterIndex = (stutterIndex + 1) % bufferSize;
    }
  }

  void randomPosition() {
    quantize = rand() % 100 > 60;
    Tempo::onPulse(&doRandomPosition, 0.1);
  }

  void randomPositionWithStutter() {
    quantize = rand() % 100 > 60;
    Tempo::onPulse(&incrementBufferIndex, 0.25);
    randomWrite();

    if (stutter) {
      if (rand() % 100 > 95) {
        stutter = false;
      }

      Pedal::setPosition(stutterBuffer[stutterIndex]);
    }
    else {
      if (rand() % 100 > 95) {
        stutter = true;
      }
      randomPosition();
    }
  }

  void randomPatchAndPosition() {
    Tempo::onPulse(&doRandomPatchAndPosition, 0.5);
  }

  void randomQuantized() {
    
  }
}
