#include <Arduino.h>
#include "./modes/modes.h"


const byte COMMAND_PATCH_CHANGE = B11000000;
const byte COMMAND_CC_CHANGE = B10110000;
const byte CC_PEDAL_POSITION = B00001011;


// RIGHT SIDE PATCHES
const byte PATCH_DETUNE_SHALLOW = 0;
const byte PATCH_DETUNE_DEEP = 1;
const byte PATCH_WHAMMY_PLUS_TWO = 2;
const byte PATCH_WHAMMY_PLUS_ONE = 3;
const byte PATCH_WHAMMY_MINUS_ONE = 4;
const byte PATCH_WHAMMY_MINUS_TWO = 5;
const byte PATCH_WHAMMY_DIVE_BOMB = 6;
const byte PATCH_WHAMMY_DROP_TUNE = 7;

// LEFT-SIDE PATCHES
const byte PATCH_HARMONY_OCTAVE = 16;
const byte PATCH_DOWN_HARMONY_FIFTH_FOURTH = 15;
const byte PATCH_DOWN_HARMONY_FOURTH_THIRD = 14;
const byte PATCH_UP_HARMONY_FIFTH_SEVENTH = 13;
const byte PATCH_UP_HARMONY_FIFTH_SIXTH = 12;
const byte PATCH_UP_HARMONY_FOURTH_FIFTH = 11;
const byte PATCH_UP_HARMONY_THIRD_FOURTH = 10;
const byte PATCH_UP_HARMONY_THIRD_THIRD = 9;
const byte PATCH_UP_HARMONY_SECOND_THIRD = 8;

const byte PATCHES[] = {
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
const byte NUM_PATCHES = sizeof(PATCHES);
byte patchIndex = 0;

const byte MODE_RANDOM_POSITION = 0;
const byte MODE_SAW_UP = 1;
const byte MODE_SAW_DOWN = 2;
const byte MODE_TRIANGLE = 3;
const byte MODE_SQUARE = 4;
const byte MODE_SEQUENCER = 5;
const byte MODE_CHAOS = 6;

const byte DEFAULT_MODE = MODE_SAW_UP;
const byte DEFAULT_PATCH = PATCH_WHAMMY_PLUS_ONE;
const byte DEFAULT_POSITION = 0;

// const byte MODES[] = {
//   MODE_RANDOM_POSITION,
//   MODE_SAW_UP,
//   MODE_SAW_DOWN,
//   MODE_TRIANGLE,
//   MODE_SQUARE,
// };
// const byte NUM_MODES = sizeof(MODES);

const byte SEQUENCE_LENGTH = 16;
byte patchSequence[SEQUENCE_LENGTH] = {
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
  DEFAULT_PATCH,
};

byte positionSequence[SEQUENCE_LENGTH] = {
  0,
  127,
  0,
  127,
  0,
  127,
  0,
  127,
  0,
  127,
  0,
  127,
  0,
  127,
  0,
  127,
};
byte sequenceIndex = 0;

boolean active = true;
byte currentMode = DEFAULT_MODE;
// boolean direction = 1;
byte currentState[2] = {DEFAULT_PATCH, DEFAULT_POSITION};

void setup() {
  Serial.begin(31250);

  if (active) {
    applyState();
  }
}

void loop() {
  // if (active) {
    runMode();
  // }
}

void applyState() {
  setPatch(currentState[0]);
  setPosition(currentState[1]);
}

void runMode() {
  switch (currentMode) {
    case MODE_RANDOM_POSITION:
      break;
    case MODE_SAW_UP:
      sawUp(currentState);
      break;
    case MODE_SAW_DOWN:
      sawDown(currentState);
      break;
    case MODE_TRIANGLE:
      Serial.println("TRIANGLE");
      triangle(currentState);
      break;
    // case MODE_SQUARE:
    //   square();
    //   break;
    // case MODE_CHAOS:
    //   chaos();
    //   break;
  }

  applyState();
  delay(100);
}

void setPatch(byte patchID) {
  // currentPatch = patchID;
  Serial.write(COMMAND_PATCH_CHANGE);
  Serial.write(PATCHES[patchID]);
}

void setPosition(byte position) {
  // currentPosition = position;
  Serial.write(COMMAND_CC_CHANGE);
  Serial.write(CC_PEDAL_POSITION);
  Serial.write(position);
}

void scheduleNext() {
  scheduleNext(10);
}

void scheduleNext(int _delay) {
  delay(_delay);
}

// byte randomPatch() {
//   if (random(100) > 60) {
//     return PATCHES[random(0, NUM_PATCHES)];
//   }
//   else {
//     return currentPatch;
//   }
// }

// byte randomPosition() {
//   if (random(100) > 60) {
//     return random(0, 127);
//   }
//   else {
//     // Sometimes stay at same position.
//     return currentPosition;
//   }
// }

// void sawUp() {
//   increaseCurrentPosition(1, true);
//   scheduleNext();
// }

// void sawDown() {
//   decreasecurrentPosition(1, true);
//   scheduleNext();
// }

// void triangle() {
//   if (direction) {
//     increaseCurrentPosition(1, false);
//     if (currentPosition == 127) {
//       direction = !direction;
//     }
//   }
//   else {
//     decreasecurrentPosition(1, false);
//     if (currentPosition == 0) {
//       direction = !direction;
//     }
//   }
//   scheduleNext();
// }

// void square() {
//   sequencePosition(positionSequence);
//   scheduleNext(500);
// }

// void chaos() {
//   setPosition(randomPosition());
//   setPatch(randomPatch());
//   scheduleNext();
// }

// void mapOfTheProblematique() {
//   // TODO
// }

// void sequencePosition(byte positions[]) {
//   setPosition(positions[sequenceIndex]);
//   sequenceIndex = (sequenceIndex + 1) % SEQUENCE_LENGTH;
// }

// void increaseCurrentPosition(int delta, boolean wrap) {
//   if (wrap) {
//     setPosition((currentPosition + delta) % 128);
//   }
//   else {
//     int result = currentPosition + delta;
//     setPosition(max(0, min(127, result)));
//   }
// }

// void decreasecurrentPosition(int delta, boolean wrap) {
//   return increaseCurrentPosition(-delta, wrap);
// }
