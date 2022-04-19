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

    void calcDelta() {
      delta = (Frame::getFrameTime() / Tempo::getPulseMillis()) * range;
    }
  }

  void sawUp() {
    calcDelta();
    // std::cout << delta;
    // std::cout << "\n";
    Pedal::setPosition(fmod(Pedal::getPosition() + delta, 128));
  }

  void sawDown() {
    calcDelta();
    // std::cout << delta;
    // std::cout << "\n";
    Pedal::setPosition(fmod((128 + Pedal::getPosition() - delta), 128));
  }
}
