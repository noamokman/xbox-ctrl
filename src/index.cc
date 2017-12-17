#include <nan.h>
#include "Off.h"
#include "Vibrate.h"
#include "List.h"

NAN_MODULE_INIT(init) {
  Off::init(target);
  Vibrate::init(target);
  List::init(target);
}

NODE_MODULE(xboxCtrl, init)