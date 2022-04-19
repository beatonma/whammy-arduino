#include "./tempo.h"


namespace {
  unsigned int tempoBpm; // bpm
  double pulseMillis; // Number of milliseconds between beats

  double tempoToPulseMillis(unsigned int tempo) {
    return (60.0 / (double) tempo) * 100.0;
  }
}

void Tempo::setTempo(unsigned int bpm) {
  tempoBpm = bpm;
  pulseMillis = tempoToPulseMillis(bpm);
}

double Tempo::getPulseMillis() {
  return pulseMillis;
}