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

    void _anyNote() {
      noteIndex = rand() % 8;
    }
  }

  const double** getScale() {
    return SCALES[scaleIndex];
  }

  void run() {
    Tempo::onPulse(_anyNote, 0.25);
    Pedal::setPosition((*SCALES)[scaleIndex][noteIndex]);
  }

  double anyNote() {
    noteIndex = rand() % 8;
    return (*SCALES)[scaleIndex][noteIndex];
  }

  void next() {
    scaleIndex = (scaleIndex + 1) % NUM_SCALES;
  }

  void anyScale() {
    scaleIndex = rand() % NUM_SCALES;
  }
}