#ifndef H_FRAME
#define H_FRAME

namespace Frame {
  void setTimestamp(unsigned long time);

  unsigned long getTime();
  double getFrameDelta(); // Milliseconds consumed during the last loop.
  double getAbsoluteDelta(); // Milliseconds since device initiation.
}
#endif
