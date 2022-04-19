#include <stdlib.h>
#include "./chaos.h"
#include "../pedal/pedal.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"

namespace Chaos {
  namespace {
    unsigned long lastChange = 0;
    // bool stutter = false;
    // double stutterBuffer[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // uint8_t stutterIndex = 0;

    double anyPosition() {
      return rand() % 128;
    }
  }

  void randomPosition() {
    if (Frame::getTime() - lastChange > (0.1 * Tempo::getPulseMillis())) {
      Pedal::setPosition(anyPosition());
      lastChange = Frame::getTime();
    }
  }
}

// void chaos() {
//   setPosition(randomPosition());
//   setPatch(randomPatch());
//   scheduleNext();
// }
