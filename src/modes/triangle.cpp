#include <stdint.h>
#include "./util.cpp"
#include <math.h>

// bool direction_ = 1;
// unsigned long timestamp_ = 0;  // Current time
// unsigned long previousTimestamp_ = 0;
// unsigned long timeDelta_ = 0;
// unsigned long tempoMillis_ = 1;
// double delta_ = 0;
// double result_;

void triangle(uint8_t* state, unsigned int tempo) {
  // timestamp_ = millis();
  // tempoMillis_ = tempoToPulseDelay(tempo);

  // timeDelta_ = timestamp_ - previousTimestamp_;

  // // Ramp up and down each beat -> delta uses half of tempoMillis.
  // delta_ = (double) timeDelta_ / (0.5 * tempoMillis_) * 127.0;
  // if (direction_) {
  //   result_ = state[1] + delta_;
  //   if (result_ > 127) {
  //     result_ = 127 - (result_ - 127);
  //     direction_ = !direction_;
  //   }
  // }
  // else {
  //   result_ = state[1] - delta_;
  //   if (result_ < 0) {
  //     result_ = -result_;
  //     direction_ = !direction_;
  //   }
  // }
  // state[1] = round(result_);

  // if (timestamp_ >= eventTimestamp_ + tempoMillis_) {
  //   if (direction_) {
  //     increaseCurrentPosition(1, false, state);
  //     if (state[1] == 127) {
  //       direction_ = !direction_;
  //     }
  //   }
  //   else {
  //     decreaseCurrentPosition(1, false, state);
  //     if (state[1] == 0) {
  //       direction_ = !direction_;
  //     }
  //   }
  //   eventTimestamp_ = timestamp_;
  // }
}
