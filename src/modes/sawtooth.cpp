// #include "./util.cpp"
#include <stdint.h>
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "./sawtooth.h"

namespace Sawtooth {
  namespace {
    double delta;
    double range = 127.0;

    void calcDelta() {
      delta = (Frame::getFrameTime() / Tempo::getPulseMillis()) * range;
    }
  }

  void sawUp(uint8_t* state) {
    calcDelta();
    state[1] = (int) (state[1] + delta) % 128;
  }

  void sawDown(uint8_t* state) {
    calcDelta();

    state[1] = (int) (128.0 + state[1] - delta) % 128;
  }
}
