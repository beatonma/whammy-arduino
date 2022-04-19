/** @file */
#include "input.h"
#include <stdlib.h>

class AbstractPotentiometerHandler: AbstractInputHandler
{
  static const int ANALOG_READ_TOLERANCE = 5;  // Ignore changes in value smaller than this

public:
  // Minimum change between previous_value_ and current_value_ that is considered
  // to be a purposeful action and not just caused by noise in the circuit.
  // static const int NOISE_FLOOR = 5;

  AbstractPotentiometerHandler(uint8_t pin): AbstractInputHandler(pin)
  {

  }

  virtual void onValueChanged(int new_value) {};
  virtual void onProgressChanged(double progress) {};

  void setup(void) {

  }

  void update(void)
  {
    current_value_ = readAnalog();
    value_difference_ = abs(previous_value_ - current_value_);

    if (value_difference_ > ANALOG_READ_TOLERANCE) {
      onValueChanged(current_value_);
      progress_ = (double) current_value_ / 1023.0;
      onProgressChanged(progress_);
      previous_value_ = current_value_;
    }
  }

protected:
  int previous_value_ = 512;
  int current_value_ = 512;
  int value_difference_ = 0;
  double progress_ = 0.0;

  unsigned long action_started_timestamp_ = 0;
  unsigned long current_timestamp_ = 0;
};
