#ifndef H_CONFIG
#define H_CONFIG

#include <stdint.h>
#include "./modes/modes.h"
#include "./pedal/patches.h"

const uint8_t DEFAULT_PATCH = PATCH_WHAMMY_PLUS_ONE;
const uint8_t DEFAULT_POSITION = 0;

const uint8_t PIN_BUTTON_ON_OFF = 9;
const uint8_t PIN_BUTTON_MODIFIER = 5;
const uint8_t PIN_BUTTON_MODE = 7;

const uint8_t PIN_POT_TEMPO = 6;
const uint8_t PIN_LED = 11;

const uint8_t MAX_BRIGHTNESS = 90;

#endif
