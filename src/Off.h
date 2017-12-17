#include <nan.h>

class Off {
 public:
  static NAN_MODULE_INIT(init);
  static NAN_METHOD(off);
  static NAN_METHOD(offAll);
 private:
  Off() {}
};