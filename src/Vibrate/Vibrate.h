#include <nan.h>

class Vibrate {
 public:
  static NAN_MODULE_INIT(init);
  static NAN_METHOD(vibrate);
  static NAN_METHOD(vibrateAll);
  static NAN_METHOD(vibrateSync);
  static NAN_METHOD(vibrateAllSync);
 private:
  Vibrate() {}
};