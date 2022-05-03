#ifndef H_CONFIG
#define H_CONFIG

#include "./src/pedal/patches.h"

const double MAX_TEMPO = 800.0;
const double MIN_TEMPO = 1.0;
const double TEMPO_RANGE = (MAX_TEMPO - MIN_TEMPO);

const uint8_t DEFAULT_PATCH = PATCH_WHAMMY_PLUS_ONE;
const double DEFAULT_POSITION = 127.0;

const uint8_t PIN_BUTTON_ON_OFF = 4;
const uint8_t PIN_BUTTON_MODIFIER = 8;
const uint8_t PIN_BUTTON_MODE = 6;

const uint8_t PIN_POT_TEMPO = 4;
const uint8_t PIN_LED = 10;

const uint8_t MAX_BRIGHTNESS = 90;

#endif
