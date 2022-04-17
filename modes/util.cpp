#ifndef H_UTIL
#define H_UTIL

int _result = 0;

byte increaseCurrentPosition(int delta, boolean wrap, byte* state) {
  _result = state[1] + delta;
  if (wrap) {
    return _result % 128;
  }
  else {
    return max(0, min(127, _result));
  }
}

byte decreaseCurrentPosition(int delta, boolean wrap, byte* state) {
  return increaseCurrentPosition(-delta, wrap, state);
}
#endif
