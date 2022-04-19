#include "./tempo.h"
#include "../frame/frame.h"


namespace Tempo {
  namespace {
    unsigned long lastStep = 0;
    double tempoBpm; // bpm
    double pulseMillis; // Number of milliseconds between beats
  }

  void setTempo(double bpm) {
    tempoBpm = bpm;
    pulseMillis = 60000.0 / bpm;
  }

  double getPulseMillis() {
    return pulseMillis;
  }

  double getTempoBpm() {
    return tempoBpm;
  }
  
  void onPulse( void (*f)(), double multiplier) {
    if (Frame::getTime() - lastStep >= (multiplier * getPulseMillis())) {
      (*f)();
      lastStep = Frame::getTime();
    }
  }
}