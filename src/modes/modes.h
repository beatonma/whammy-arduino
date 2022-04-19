#ifndef H_MODES
#define H_MODES

#define MODE_RANDOM_POSITION 0
#define MODE_SAW_UP 1
#define MODE_SAW_DOWN 2
#define MODE_TRIANGLE 3
#define MODE_SQUARE 4
#define MODE_RANDOM_PATCH_AND_POSITION 5
#define MODE_MOTP 6
#define MODE_TRUE_CHAOS 7

const uint8_t MODES[] = {
  MODE_RANDOM_POSITION, // Move pedal to any position
  MODE_SAW_UP,      // Move toe down
  MODE_SAW_DOWN,    // Move heel down
  MODE_TRIANGLE,    // Heel-toe, heel-toe
  MODE_SQUARE,      // On/off
  MODE_RANDOM_PATCH_AND_POSITION, // Move pedal to any position with any patch.
  MODE_MOTP,        // Map of the Problematique
  MODE_TRUE_CHAOS,  // Randomly select a mode on every tempo pulse.
};
const uint8_t NUM_MODES = sizeof(MODES);

void runMode();
void runAnyMode();
void nextMode();
void previousMode();

#endif
