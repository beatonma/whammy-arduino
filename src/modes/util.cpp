// #include <stdint.h>
// #ifndef H_UTIL
// #define H_UTIL


// int _result = 0;

// void increaseCurrentPosition(int delta, bool wrap, uint8_t* state) {
//   _result = state[1] + delta;
//   if (wrap) {
//     state[1] = _result % 128;
//   }
//   else {
//     state[1] = max(0, min(127, _result));
//   }
// }

// void decreaseCurrentPosition(int delta, bool wrap, uint8_t* state) {
//   increaseCurrentPosition(-delta, wrap, state);
// }

// unsigned int tempoToPulseDelay(unsigned int tempo) {
//   return (int) ((60.0 / (double) tempo) * 100.0);
// }
// #endif
