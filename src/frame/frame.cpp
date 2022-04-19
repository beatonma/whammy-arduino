#include "./frame.h"

namespace {
  unsigned long timestamp;
  unsigned long previousTimestamp = 0;
  double delta;
}

void Frame::setTimestamp(unsigned long time) {
  previousTimestamp = timestamp;
  timestamp = time;
  delta = timestamp - previousTimestamp;
}

double Frame::getFrameTime() {
  return delta;
}