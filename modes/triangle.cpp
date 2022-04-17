#include <stdint.h>
#include "./util.cpp"

boolean _direction = 1;

void triangle(uint8_t* state) {
  if (_direction) {
    increaseCurrentPosition(1, false, state);
    if (state[1] == 127) {
      _direction = !_direction;
    }
  }
  else {
    decreaseCurrentPosition(1, false, state);
    if (state[1] == 0) {
      _direction = !_direction;
    }
  }
}
