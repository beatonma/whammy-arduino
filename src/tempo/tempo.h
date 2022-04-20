#ifndef H_TEMPO
#define H_TEMPO

namespace Tempo {
  void setTempo(double bpm);
  double getTempoBpm();
  double getPulseMillis();
  double getFrequency();

  /**
   * Run the given function on each pulse.
   */
  void onPulse( void (*f)(), double multiplier);
}

#endif