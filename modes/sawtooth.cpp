#include "./util.cpp"

void sawUp(byte* state) {
  state[1] = increaseCurrentPosition(1, true, state);
}

void sawDown(byte* state) {
  state[1] = decreaseCurrentPosition(1, true, state);
}
