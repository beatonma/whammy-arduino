#include <stdint.h>
#include "./util.cpp"
#include <math.h>
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../pedal/pedal.h"


namespace Triangle {

  namespace {
    double delta;
    double result;
    bool direction = true;
  }

  void triangle() {
    delta = (Frame::getFrameTime() / Tempo::getPulseMillis()) * 255.0;

    if (direction) {
      result = Pedal::getPosition() + delta;
      if (result > 127.0) {
        // bounce back from limit.
        result = 127.0 - (result - 127.0);
        direction = !direction;
      }
    }
    else {
      result = Pedal::getPosition() - delta;
      if (result < 0) {
        // bounce back from limit.
        result = -result;
        direction = !direction;
      }
    }
    Pedal::setPosition(result);
  }
}
