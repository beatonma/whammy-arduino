#include <stdint.h>
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
    delta = (Frame::getFrameTime() / Tempo::getPulseMillis()) * (Pedal::getMaxPosition() * 2.0);

    if (direction) {
      result = Pedal::getPosition() + delta;
      if (result > Pedal::getMaxPosition()) {
        // bounce back from limit.
        result = Pedal::getMaxPosition() - (result - Pedal::getMaxPosition());
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
