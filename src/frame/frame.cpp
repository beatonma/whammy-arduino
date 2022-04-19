#include "./frame.h"

namespace Frame {
  namespace {
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

  double getFrameTime() {
    return delta;
  }
}