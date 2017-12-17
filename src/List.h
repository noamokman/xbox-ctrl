#include <nan.h>

class List {
 public:
  static NAN_MODULE_INIT(init);
  static NAN_METHOD(list);
 private:
  List() {}
};