#include "./patches.h"
#include <stdlib.h>

namespace Patch {
  uint8_t anyPatch() {
    return PATCHES[rand() % NUM_PATCHES];
  }
}