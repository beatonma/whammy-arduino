#ifndef H_MODES
#define H_MODES

#define MODE_RANDOM_POSITION 0
#define MODE_RANDOM_POSITION_STUTTER 1
#define MODE_SAW_UP 2
#define MODE_SAW_DOWN 3
#define MODE_TRIANGLE 4
#define MODE_SINE 5
#define MODE_SQUARE 6
#define MODE_RANDOM_PATCH_AND_POSITION 7
#define MODE_MOTP 8
#define MODE_TRUE_CHAOS 9
#define MODE_SCALE 10

const uint8_t MODES[] = {
  MODE_SCALE,       // Move pedal to simulate a mode e.g. phyrigian.
  MODE_RANDOM_POSITION, // Move pedal to any position
  MODE_RANDOM_POSITION_STUTTER,
  MODE_SAW_UP,      // Move toe down
  MODE_SAW_DOWN,    // Move heel down
  MODE_TRIANGLE,    // Linear heel-toe
  MODE_SINE,        // Sine wave heel-toe
  MODE_SQUARE,      // On/off
  MODE_RANDOM_PATCH_AND_POSITION, // Move pedal to any position with any patch.
  MODE_MOTP,        // Map of the Problematique
  MODE_TRUE_CHAOS,  // Randomly select a mode on every tempo pulse.
};
#define NUM_MODES sizeof(MODES)

namespace Mode {
  void run();
  void runAny();
  void run(uint8_t modeID);
  void next();
  void previous();
}

#endif
