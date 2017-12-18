#include <nan.h>
#include "Off/Off.h"
#include "Vibrate/Vibrate.h"
#include "List/List.h"

NAN_MODULE_INIT(init) {
  Off::init(target);
  Vibrate::init(target);
  List::init(target);
}

NODE_MODULE(xboxCtrl, init)