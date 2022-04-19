#include "./frame.h"

namespace {
  unsigned long timestamp;
  unsigned long previousTimestamp = 0;
  unsigned long delta;
}

void Frame::setTimestamp(unsigned long time) {
  previousTimestamp = timestamp;
  timestamp = time;
  delta = timestamp - previousTimestamp;
}

unsigned long Frame::getFrameTime() {
  return delta;
}