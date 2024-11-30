#ifndef H_CONFIG
#define H_CONFIG

/**
 * IMPORTANT
 *
 * Pedal hardware selection.
 *
 * Different whammy pedal variants use different MIDI codes.
 * Set PEDAL_HARDWARE to match your pedal from the options
 * below.
 */

#define WHAMMY_IV 1 // Whammy IV, default
#define WHAMMY_DT 2 // Whammy DT https://digitech.com/dp/whammy-dt/

// // Change this to the pedal you are using from the options above
#define PEDAL_HARDWARE WHAMMY_IV
// /**
//  * End of pedal hardware selection
//  */

#include "./src/pedal/patches.h"

const double MAX_TEMPO = 800.0;
const double MIN_TEMPO = 1.0;
const double TEMPO_RANGE = (MAX_TEMPO - MIN_TEMPO);

const uint8_t DEFAULT_PATCH = PATCH_WHAMMY_PLUS_ONE;
const double DEFAULT_POSITION = 127.0;

const uint8_t PIN_BUTTON_ON_OFF = 4;
const uint8_t PIN_BUTTON_MODIFIER = 5;
const uint8_t PIN_BUTTON_MODE = 6;

const uint8_t PIN_POT_TEMPO = 4;
const uint8_t PIN_LED_RED = 11;
const uint8_t PIN_LED_GREEN = 10;
const uint8_t PIN_LED_BLUE = 9;

const uint8_t MAX_BRIGHTNESS = 180;

#endif
