#ifndef H_MODES
#define H_MODES

#define MODE_RANDOM_POSITION 0
#define MODE_SAW_UP 1
#define MODE_SAW_DOWN 2
#define MODE_TRIANGLE 3
#define MODE_SQUARE 4
#define MODE_SEQUENCER 5
#define MODE_CHAOS 6

const uint8_t MODES[] = {
  MODE_SAW_UP,
  MODE_SAW_DOWN,
  // MODE_TRIANGLE
};
const uint8_t NUM_MODES = sizeof(MODES);

void runMode(uint8_t* state);
void nextMode();

#endif
