#ifndef H_PEDAL
#define H_PEDAL

#include "./midi.h"
#include "./patches.h"

#define POSITION_NULL -1

#define POSITION_SEMITONE 127.0 / 12.0
#define semitones(N) (POSITION_SEMITONE * (double) N)
#define POSITION_ROOT 0.0
#define POSITION_MINOR_SECOND semitones(1)
#define POSITION_MAJOR_SECOND semitones(2)
#define POSITION_MINOR_THIRD semitones(3)
#define POSITION_MAJOR_THIRD semitones(4)
#define POSITION_PERFECT_FOURTH semitones(5)
#define POSITION_TRITONE semitones(6)
#define POSITION_PERFECT_FIFTH semitones(7)
#define POSITION_MINOR_SIXTH semitones(8)
#define POSITION_MAJOR_SIXTH semitones(9)
#define POSITION_MINOR_SEVENTH semitones(10)
#define POSITION_MAJOR_SEVENTH semitones(11)
#define POSITION_OCTAVE semitones(12)

const double QUANTIZED_POSITIONS[] = {
  POSITION_ROOT,
  POSITION_MINOR_SECOND,
  POSITION_MAJOR_SECOND,
  POSITION_MINOR_THIRD,
  POSITION_MAJOR_THIRD,
  POSITION_PERFECT_FOURTH,
  POSITION_TRITONE,
  POSITION_PERFECT_FIFTH,
  POSITION_MINOR_SIXTH,
  POSITION_MAJOR_SIXTH,
  POSITION_MINOR_SEVENTH,
  POSITION_MAJOR_SEVENTH,
  POSITION_OCTAVE,
};
#define NUM_QUANTIZED_POSITIONS 13


namespace Pedal {
  void setPatch(uint8_t patchID);
  void setPosition(double position);
  void setMaxPosition(double max);
  void off();
  
  uint8_t getPatch();
  double getPosition();
  double getMaxPosition();

  /**
   * Send the current patch and position to the actual pedal.
   */
  void apply();

  uint8_t anyPatch();
  double anyPosition();
  double anyQuantizedPosition();
}

#endif