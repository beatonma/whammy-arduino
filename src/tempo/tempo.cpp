#include "./tempo.h"


namespace {
  double tempoBpm; // bpm
  double pulseMillis; // Number of milliseconds between beats

  double tempoToPulseMillis(double bpm) {
    return 60000.0 / bpm;
  }
}

void Tempo::setTempo(double bpm) {
  tempoBpm = bpm;
  pulseMillis = tempoToPulseMillis(bpm);
}

double Tempo::getPulseMillis() {
  return pulseMillis;
}

double Tempo::getTempoBpm() {
  return tempoBpm;
}