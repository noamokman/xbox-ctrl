#include <nan.h>
#include "windows.h"
#include "xinput.h"
#include "helper.h"
#include "List.h"
#include "listActions.h"
#include "ListWorker.cc"

#pragma comment(lib, "XInput.lib")

using namespace std;
using namespace helper;
using namespace listActions;

NAN_MODULE_INIT(List::init) {
  Nan::Export(target, "list", List::list);
  Nan::Export(target, "listSync", List::listSync);
}

NAN_METHOD(List::listSync) {
  info.GetReturnValue().Set(vectorToArray(listActions::list()));
}

NAN_METHOD(List::list) {
  Nan::AsyncQueueWorker(new ListWorker(
      new Nan::Callback(info[0].As<v8::Function>())
  ));
}