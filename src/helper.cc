#include "helper.h"

namespace helper
{
  int getIndexFromInfo(Nan::NAN_METHOD_ARGS_TYPE info) {
    int index = Nan::To<int>(info[0]).FromJust();

    return index < 0 || index > XUSER_MAX_COUNT ? -1 : index;
  }

  v8::Local<v8::Array> vectorToArray(std::vector<int> vec) {
    v8::Local<v8::Array> arr = Nan::New<v8::Array>();

    int arrayIndex = 0;

    for (auto const &element: vec) {
      arr->Set(arrayIndex++, Nan::New<v8::Number>(element));
    }

    return arr;
  }
}