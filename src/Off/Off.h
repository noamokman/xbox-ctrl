#include <nan.h>

class Off {
 public:
  static NAN_MODULE_INIT(init);
  static NAN_METHOD(off);
  static NAN_METHOD(offAll);
  static NAN_METHOD(offSync);
  static NAN_METHOD(offAllSync);
 private:
  Off() {}
};