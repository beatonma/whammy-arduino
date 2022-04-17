#include "./util.cpp"

void sawUp(uint8_t* state) {
  increaseCurrentPosition(1, true, state);
}

void sawDown(uint8_t* state) {
  decreaseCurrentPosition(1, true, state);
}
