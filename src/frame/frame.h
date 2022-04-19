#ifndef H_FRAME
#define H_FRAME

namespace Frame {
  void setTimestamp(unsigned long time);

  unsigned long getTime();
  double getFrameTime(); // Milliseconds consumed during the last loop.
}
#endif
