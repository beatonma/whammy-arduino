#include "./scales.h"
#include "../tempo/tempo.h"
#include <stdlib.h>

namespace Scale {
  namespace {
    uint8_t scaleIndex = 0;
    uint8_t noteIndex = 0;

    const double* SCALES[NUM_SCALES][8] = {
      Scale::aeolian,
      Scale::dorian,
      Scale::phrygian,
      Scale::lydian,
      Scale::mixolydian,
      Scale::aeolian,
      Scale::locrian,
    };

    void nextNote() {
      noteIndex = (noteIndex + 1) % 8;
    }

    void anyNote() {
      noteIndex = rand() % 8;
    }
  }

  const double** getScale() {
    return SCALES[scaleIndex];
  }

  void scale() {
    Tempo::onPulse(anyNote, 0.25);
    Pedal::setPosition((*SCALES)[scaleIndex][noteIndex]);//[noteIndex]);
  }

  void nextScale() {
    scaleIndex = (scaleIndex + 1) % NUM_SCALES;
  }

  void anyScale() {
    scaleIndex = rand() % NUM_SCALES;
  }
}