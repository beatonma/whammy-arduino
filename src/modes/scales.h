#ifndef H_SCALES
#define H_SCALES

#include "../pedal/pedal.h"

#define NUM_SCALES 7

#define MODE_IONIAN 0
#define MODE_DORIAN 1
#define MODE_PHRYGIAN 2
#define MODE_LYDIAN 3
#define MODE_MIXOLYDIAN 4
#define MODE_AEOLIAN 5
#define MODE_LOCRIAN 6

namespace Scale {
  const double ionian[8] = {
    POSITION_ROOT,
    POSITION_MAJOR_SECOND,
    POSITION_MAJOR_THIRD,
    POSITION_PERFECT_FOURTH,
    POSITION_PERFECT_FIFTH,
    POSITION_MAJOR_SIXTH,
    POSITION_MAJOR_SEVENTH,
    POSITION_OCTAVE,
  };

  const double dorian[8] = {
    POSITION_ROOT,
    POSITION_MAJOR_SECOND,
    POSITION_MINOR_THIRD,
    POSITION_PERFECT_FOURTH,
    POSITION_PERFECT_FIFTH,
    POSITION_MAJOR_SIXTH,
    POSITION_MINOR_SEVENTH,
    POSITION_OCTAVE,
  };

  const double phrygian[8] = {
    POSITION_ROOT,
    POSITION_MINOR_SECOND,
    POSITION_MINOR_THIRD,
    POSITION_PERFECT_FOURTH,
    POSITION_PERFECT_FIFTH,
    POSITION_MINOR_SIXTH,
    POSITION_MINOR_SEVENTH,
    POSITION_OCTAVE,
  };

  const double lydian[8] = {
    POSITION_ROOT,
    POSITION_MAJOR_SECOND,
    POSITION_MAJOR_THIRD,
    POSITION_TRITONE,
    POSITION_PERFECT_FIFTH,
    POSITION_MAJOR_SIXTH,
    POSITION_MAJOR_SEVENTH,
    POSITION_OCTAVE,
  };

  const double mixolydian[8] = {
    POSITION_ROOT,
    POSITION_MAJOR_SECOND,
    POSITION_MAJOR_THIRD,
    POSITION_PERFECT_FOURTH,
    POSITION_PERFECT_FIFTH,
    POSITION_MAJOR_SIXTH,
    POSITION_MINOR_SEVENTH,
    POSITION_OCTAVE,
  };

  const double aeolian[8] = {
    POSITION_ROOT,
    POSITION_MAJOR_SECOND,
    POSITION_MINOR_THIRD,
    POSITION_PERFECT_FOURTH,
    POSITION_PERFECT_FIFTH,
    POSITION_MINOR_SIXTH,
    POSITION_MINOR_SEVENTH,
    POSITION_OCTAVE,
  };

  const double locrian[8] = {
    POSITION_ROOT,
    POSITION_MINOR_SECOND,
    POSITION_MINOR_THIRD,
    POSITION_PERFECT_FOURTH,
    POSITION_TRITONE,
    POSITION_MINOR_SIXTH,
    POSITION_MINOR_SEVENTH,
    POSITION_OCTAVE,
  };

  // const double** get(uint8_t scaleID);
  const double** getScale();
  void scale();
  void nextScale();
  void anyScale();

  // const double* SCALES[NUM_SCALES][8] = {
  //   Scale::aeolian,
  //   Scale::dorian,
  //   Scale::phrygian,
  //   Scale::lydian,
  //   Scale::mixolydian,
  //   Scale::aeolian,
  //   Scale::locrian,
  // };
}


#endif