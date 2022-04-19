#ifndef H_TEMPO
#define H_TEMPO

namespace Tempo {
  void setTempo(double bpm);
  double getTempoBpm();
  double getPulseMillis();

  void onPulse( void (*f)(), double multiplier);
}

#endif