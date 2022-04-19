#include <math.h>
#include <stdint.h>
#include "./sawtooth.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../pedal/pedal.h"

namespace Sawtooth {
  namespace {
    double delta;

    double calcDelta() {
      return (Frame::getFrameTime() / Tempo::getPulseMillis()) * Pedal::getMaxPosition();
    }
  }

  void sawUp() {
    delta = calcDelta();
    Pedal::setPosition(
      fmod(
        Pedal::getPosition() + delta,
        Pedal::getMaxPosition() + 1.0
      )
    );
  }

  void sawDown() {
    delta = calcDelta();
    Pedal::setPosition(
      fmod(
        Pedal::getMaxPosition() + Pedal::getPosition() - delta,
        Pedal::getMaxPosition() + 1.0
      )
    );
  }
}
