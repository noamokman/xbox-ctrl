#include <nan.h>
#include <string>
#include "windows.h"
#include "xinput.h"
#include "Off.h"
#include "helper.h"
#include "offActions.h"
#include "OffWorker.cc"

#pragma comment(lib, "XInput.lib")

using namespace std;
using namespace helper;
using namespace offActions;

NAN_MODULE_INIT(Off::init) {
  Nan::Export(target, "off", Off::off);
  Nan::Export(target, "offAll", Off::offAll);
  Nan::Export(target, "offSync", Off::offSync);
  Nan::Export(target, "offAllSync", Off::offAllSync);
}

NAN_METHOD(Off::offSync) {
  int index = getIndexFromInfo(info);

	if(index == -1) {
	  return Nan::ThrowTypeError("invalid controller index");
	}

	std::string error = offActions::off(index);

	if(!error.empty()) {
	  return Nan::ThrowError(error.c_str());
	}
}

NAN_METHOD(Off::offAllSync) {
	std::string error = offActions::offAll();

	if(!error.empty()) {
	  return Nan::ThrowError(error.c_str());
	}
}

NAN_METHOD(Off::off) {
  int index = getIndexFromInfo(info);

  if(index == -1) {
    return Nan::ThrowTypeError("invalid controller index");
  }

  Nan::AsyncQueueWorker(new OffWorker(
      index,
      new Nan::Callback(info[1].As<v8::Function>())
  ));
}

NAN_METHOD(Off::offAll) {
  Nan::AsyncQueueWorker(new OffWorker(
      -1,
      new Nan::Callback(info[0].As<v8::Function>())
  ));
}