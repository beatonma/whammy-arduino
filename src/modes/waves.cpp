#include <stdint.h>
#include "./waves.h"
#include "./continuous.h"
#include "./sawtooth.h"

namespace Waves {
  const uint8_t NUM_WAVES = 4;

  const uint8_t WAVE_SINE = 0;
  const uint8_t WAVE_SAW_UP = 1;
  const uint8_t WAVE_SAW_DOWN = 2;
  const uint8_t WAVE_TRIANGLE = 3;

  uint8_t index = 0;
    
  void run() {
    switch (index) {
      case WAVE_SINE:
        Continuous::sine();
        break;
      case WAVE_SAW_UP:
        Sawtooth::sawUp();
        break;
      case WAVE_SAW_DOWN:
        Sawtooth::sawDown();
        break;
      case WAVE_TRIANGLE:
        Continuous::triangle();
        break;
    }
  }

  void next() {
    index = (index + 1) % NUM_WAVES;
  }
}