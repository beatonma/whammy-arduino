#include <stdlib.h>
#include "./chaos.h"
#include "../pedal/pedal.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../pedal/pedal.h"

namespace Chaos {
  namespace {
    double anyPosition() {
      return rand() % (int) Pedal::getMaxPosition();
    }

    bool stutter = false;
    double stutterBuffer[] = {
      anyPosition(), anyPosition(), anyPosition(), anyPosition(),
      anyPosition(), anyPosition(), anyPosition(), anyPosition(),
      anyPosition(), anyPosition(), anyPosition(), anyPosition(),
      anyPosition(), anyPosition(), anyPosition(), anyPosition()
    };
    uint8_t stutterIndex = 0;

    void doRandomPatchAndPosition() {
      Pedal::setPosition(anyPosition());
      Pedal::setPatch(Patch::anyPatch());
    }

    void doRandomPosition() {
      Pedal::setPosition(anyPosition());
    }

    // void 
  }

  void randomPosition() {
    Tempo::onPulse(&doRandomPosition, 0.1);
  }

  void randomPatchAndPosition() {
    Tempo::onPulse(&doRandomPatchAndPosition, 0.5);
  }
}
