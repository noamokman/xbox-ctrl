#include <nan.h>

class Vibrate {
 public:
  static NAN_MODULE_INIT(init);
  static NAN_METHOD(vibrate);
  static NAN_METHOD(vibrateAll);
 private:
  Vibrate() {}
};