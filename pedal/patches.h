#ifndef H_PATCHES
#define H_PATCHES

#include <stdint.h>

// RIGHT SIDE PATCHES
const uint8_t PATCH_DETUNE_SHALLOW = 0;
const uint8_t PATCH_DETUNE_DEEP = 1;
const uint8_t PATCH_WHAMMY_PLUS_TWO = 2;
const uint8_t PATCH_WHAMMY_PLUS_ONE = 3;
const uint8_t PATCH_WHAMMY_MINUS_ONE = 4;
const uint8_t PATCH_WHAMMY_MINUS_TWO = 5;
const uint8_t PATCH_WHAMMY_DIVE_BOMB = 6;
const uint8_t PATCH_WHAMMY_DROP_TUNE = 7;

// LEFT-SIDE PATCHES
const uint8_t PATCH_HARMONY_OCTAVE = 16;
const uint8_t PATCH_DOWN_HARMONY_FIFTH_FOURTH = 15;
const uint8_t PATCH_DOWN_HARMONY_FOURTH_THIRD = 14;
const uint8_t PATCH_UP_HARMONY_FIFTH_SEVENTH = 13;
const uint8_t PATCH_UP_HARMONY_FIFTH_SIXTH = 12;
const uint8_t PATCH_UP_HARMONY_FOURTH_FIFTH = 11;
const uint8_t PATCH_UP_HARMONY_THIRD_FOURTH = 10;
const uint8_t PATCH_UP_HARMONY_THIRD_THIRD = 9;
const uint8_t PATCH_UP_HARMONY_SECOND_THIRD = 8;

const uint8_t PATCHES[] = {
  PATCH_DETUNE_SHALLOW,
  PATCH_DETUNE_DEEP,
  PATCH_WHAMMY_PLUS_TWO,
  PATCH_WHAMMY_PLUS_ONE,
  PATCH_WHAMMY_MINUS_ONE,
  PATCH_WHAMMY_MINUS_TWO,
  PATCH_WHAMMY_DIVE_BOMB,
  PATCH_WHAMMY_DROP_TUNE,
  PATCH_HARMONY_OCTAVE,
  PATCH_DOWN_HARMONY_FIFTH_FOURTH,
  PATCH_DOWN_HARMONY_FOURTH_THIRD,
  PATCH_UP_HARMONY_FIFTH_SEVENTH,
  PATCH_UP_HARMONY_FIFTH_SIXTH,
  PATCH_UP_HARMONY_FOURTH_FIFTH,
  PATCH_UP_HARMONY_THIRD_FOURTH,
  PATCH_UP_HARMONY_THIRD_THIRD,
  PATCH_UP_HARMONY_SECOND_THIRD,
};
const uint8_t NUM_PATCHES = sizeof(PATCHES);

#endif
