#ifndef H_MODES
#define H_MODES

const uint8_t MODE_RANDOM_POSITION = 0;
const uint8_t MODE_RANDOM_POSITION_STUTTER = 1;
const uint8_t MODE_SAW_UP = 2;
const uint8_t MODE_SAW_DOWN = 3;
const uint8_t MODE_TRIANGLE = 4;
const uint8_t MODE_SINE = 5;
const uint8_t MODE_SEQUENCER = 6;
const uint8_t MODE_RANDOM_PATCH_AND_POSITION = 7;
const uint8_t MODE_TRUE_CHAOS = 8;
const uint8_t MODE_SCALE = 9;
const uint8_t MODE_WAVES = 10; // Triangle, sine, saw-up, saw-down.

const uint8_t MODES[] = {
  MODE_WAVES, // Sine, saw-up, saw-down, triangle.
  MODE_SEQUENCER,
  MODE_SCALE,       // Move pedal to simulate a mode e.g. phyrigian.
  // MODE_RANDOM_POSITION, // Move pedal to any position
  MODE_RANDOM_POSITION_STUTTER,
  // MODE_RANDOM_PATCH_AND_POSITION, // Move pedal to any position with any patch.
  MODE_TRUE_CHAOS,  // Randomly select a mode on every tempo pulse.
};
const uint8_t NUM_MODES = sizeof(MODES);

namespace Mode {
  void run();
  void runAny();
  void run(uint8_t modeID);
  void next();
  void previous();
}

#endif
