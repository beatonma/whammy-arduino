#ifndef H_MIDI
#define H_MIDI

#include <stdint.h>

const uint8_t COMMAND_PATCH_CHANGE = 0b11000000;
const uint8_t COMMAND_CC_CHANGE = 0b10110000;
const uint8_t CC_PEDAL_POSITION = 0b00001011;

#endif
