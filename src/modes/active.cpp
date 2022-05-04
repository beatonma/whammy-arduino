#include <math.h>
#include <stdint.h>
#include "./active.h"
#include "../frame/frame.h"
#include "../tempo/tempo.h"
#include "../pedal/pedal.h"
#include "../led/led.h"

namespace Active {
  namespace {
    double delta;
    double calcDelta() {
      return (Frame::getFrameDelta() / Tempo::getPulseMillis()) * Pedal::getMaxPosition();
    }
  }


  void run() {
    delta = calcDelta();
    if (Pedal::getActive()) {
      Pedal::coerceOn();
      Pedal::setPosition(fmin(255.0, Pedal::getPosition() + delta));
    }
    else {
      Pedal::setPosition(fmax(0.0, Pedal::getPosition() - delta));
      if (Pedal::getPosition() == 0.0) {
        Pedal::off();
      }
    }
  }
}