#ifndef H_PEDAL
#define H_PEDAL

#include "./midi.h"
#include "./patches.h"
#define POSITION_NULL -1

namespace Pedal {
  void setPatch(int patchID);
  void setPosition(double position);
  void setMaxPosition(double max);
  
  int getPatch();
  double getPosition();
  double getMaxPosition();

  /**
   * Send the current patch and position to the actual pedal.
   */
  void apply();
}

#endif