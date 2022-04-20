#include <math.h>
#include <stdint.h>
#include "./sawtooth.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../pedal/pedal.h"

namespace Sawtooth {
  namespace {
    double delta;
    double result;

    double calcDelta() {
      return (Frame::getFrameDelta() / Tempo::getPulseMillis()) * Pedal::getMaxPosition();
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
    result = Pedal::getPosition() - delta;
    if (result <= 0.0) {
      result = Pedal::getMaxPosition() + result;
    }
    Pedal::setPosition(result);
  }
}
