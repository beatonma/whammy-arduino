#ifndef H_MODES
#define H_MODES

#include "./sawtooth.cpp"
#include "./triangle.cpp"

const uint8_t MODE_RANDOM_POSITION = 0;
const uint8_t MODE_SAW_UP = 1;
const uint8_t MODE_SAW_DOWN = 2;
const uint8_t MODE_TRIANGLE = 3;
const uint8_t MODE_SQUARE = 4;
const uint8_t MODE_SEQUENCER = 5;
const uint8_t MODE_CHAOS = 6;

const uint8_t MODES[] = {
  MODE_SAW_DOWN,
  MODE_SAW_UP,
  MODE_TRIANGLE,
};
const uint8_t NUM_MODES = sizeof(MODES);

void runMode(uint8_t* state);
void nextMode();

#endif
