#include <nan.h>
#include "windows.h"
#include "xinput.h"
#include "Vibrate.h"
#include "helper.h"
#include "vibrateActions.h"
#include "VibrateWorker.cc"

#pragma comment(lib, "XInput.lib")

using namespace std;
using namespace helper;
using namespace vibrateActions;

NAN_MODULE_INIT(Vibrate::init) {
  Nan::Export(target, "vibrate", Vibrate::vibrate);
  Nan::Export(target, "vibrateAll", Vibrate::vibrateAll);
  Nan::Export(target, "vibrateSync", Vibrate::vibrateSync);
  Nan::Export(target, "vibrateAllSync", Vibrate::vibrateAllSync);
}

NAN_METHOD(Vibrate::vibrateSync) {
  int index = getIndexFromInfo(info);

	if(index == -1) {
	  return Nan::ThrowTypeError("invalid controller index");
	}

  int sleep = Nan::To<int>(info[1]).FromJust();

  if(sleep < 0) {
    return Nan::ThrowTypeError("sleep parameter must be positive");
  }

	vibrateActions::vibrate(index, sleep);
}

NAN_METHOD(Vibrate::vibrateAllSync) {
  int sleep = Nan::To<int>(info[0]).FromJust();

  if(sleep < 0) {
    return Nan::ThrowTypeError("sleep parameter must be positive");
  }

  vibrateActions::vibrateAll(sleep);
}

NAN_METHOD(Vibrate::vibrate) {
  int index = getIndexFromInfo(info);

  if(index == -1) {
    return Nan::ThrowTypeError("invalid controller index");
  }

  int sleep = Nan::To<int>(info[1]).FromJust();

  if(sleep < 0) {
    return Nan::ThrowTypeError("sleep parameter must be positive");
  }

  Nan::AsyncQueueWorker(new VibrateWorker(
      index,
      sleep,
      new Nan::Callback(info[2].As<v8::Function>())
  ));
}

NAN_METHOD(Vibrate::vibrateAll) {
  int sleep = Nan::To<int>(info[0]).FromJust();

  if(sleep < 0) {
    return Nan::ThrowTypeError("sleep parameter must be positive");
  }

  Nan::AsyncQueueWorker(new VibrateWorker(
      -1,
      sleep,
      new Nan::Callback(info[1].As<v8::Function>())
  ));
}