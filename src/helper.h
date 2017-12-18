#include <nan.h>
#include "xinput.h"

namespace helper
{
  int getIndexFromInfo(Nan::NAN_METHOD_ARGS_TYPE info);
  v8::Local<v8::Array> vectorToArray(std::vector<int> vec);
}