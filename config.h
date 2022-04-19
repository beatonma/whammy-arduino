#ifndef H_CONFIG
#define H_CONFIG

#define MAX_TEMPO 200
#define MIN_TEMPO 20
#define TEMPO_RANGE (MAX_TEMPO - MIN_TEMPO)

// #include <stdint.h>
// #include "./src/modes/modes.h"
#include "./src/pedal/patches.h"

#define DEFAULT_PATCH PATCH_WHAMMY_PLUS_ONE
#define DEFAULT_POSITION 127

#define PIN_BUTTON_ON_OFF 9
#define PIN_BUTTON_MODIFIER 5
#define PIN_BUTTON_MODE 7

#define PIN_POT_TEMPO 6
#define PIN_LED 11

#define MAX_BRIGHTNESS 90

#endif
