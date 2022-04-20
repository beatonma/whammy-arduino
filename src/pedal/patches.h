#ifndef H_PATCHES
#define H_PATCHES

#include <stdint.h>

#define PATCH_NULL 111
#define PATCH_OFF 26

// RIGHT SIDE PATCHES
#define PATCH_DETUNE_SHALLOW 0
#define PATCH_DETUNE_DEEP 1
#define PATCH_WHAMMY_PLUS_TWO 2
#define PATCH_WHAMMY_PLUS_ONE 3
#define PATCH_WHAMMY_MINUS_ONE 4
#define PATCH_WHAMMY_MINUS_TWO 5
#define PATCH_WHAMMY_DIVE_BOMB 6
#define PATCH_WHAMMY_DROP_TUNE 7

// LEFT-SIDE PATCHES
#define PATCH_HARMONY_OCTAVE 16
#define PATCH_DOWN_HARMONY_FIFTH_FOURTH 15
#define PATCH_DOWN_HARMONY_FOURTH_THIRD 14
#define PATCH_UP_HARMONY_FIFTH_SEVENTH 13
#define PATCH_UP_HARMONY_FIFTH_SIXTH 12
#define PATCH_UP_HARMONY_FOURTH_FIFTH 11
#define PATCH_UP_HARMONY_THIRD_FOURTH 10
#define PATCH_UP_HARMONY_THIRD_THIRD 9
#define PATCH_UP_HARMONY_SECOND_THIRD 8


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
#define NUM_PATCHES sizeof(PATCHES)

#endif
