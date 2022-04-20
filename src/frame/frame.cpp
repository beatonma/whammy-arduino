#include "./frame.h"
#include <Arduino.h>

namespace Frame {
  namespace {
    // A timestamp representing t=0, set once.
    unsigned long zeroTimestamp = millis();

    // Updated each loop().
    unsigned long timestamp;
    unsigned long previousTimestamp = 0;
    double delta;
  }

  void setTimestamp(unsigned long time) {
    previousTimestamp = timestamp;
    timestamp = time;
    delta = timestamp - previousTimestamp;
  }

  unsigned long getTime() {
    return timestamp;
  }

  double getAbsoluteDelta() {
    return timestamp - zeroTimestamp;
  }

  double getFrameDelta() {
    return delta;
  }
}