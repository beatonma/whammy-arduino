// #include "./util.cpp"
#include <stdint.h>
#include <math.h>
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "./sawtooth.h"
#include "../pedal/pedal.h"

namespace Sawtooth {
  namespace {
    double delta;
    double range = 127.0;

    double calcDelta() {
      return (Frame::getFrameTime() / Tempo::getPulseMillis()) * range;
    }
  }

  void sawUp() {
    delta = calcDelta();
    Pedal::setPosition(
      fmod(
        Pedal::getPosition() + delta,
        128.0
      )
    );
  }

  void sawDown() {
    delta = calcDelta();
    Pedal::setPosition(
      fmod(
        128.0 + Pedal::getPosition() - delta,
        128.0
      )
    );
  }
}
