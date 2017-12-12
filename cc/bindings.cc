#include "Gifx.h"

NAN_MODULE_INIT(init) {
  Gifx::Initialize(target);
}

NODE_MODULE(gifx, init);
