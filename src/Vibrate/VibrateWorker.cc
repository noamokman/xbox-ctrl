#include <nan.h>
#include "vibrateActions.h"

using namespace vibrateActions;

class VibrateWorker : public Nan::AsyncWorker {
public:
	int index;
	int sleep;

	VibrateWorker(int index, int sleep, Nan::Callback *callback)
    : Nan::AsyncWorker(callback) {
    this->index = index;
    this->sleep = sleep;
  }

	void Execute() {
    if(this->index == -1) {
      vibrateActions::vibrateAll(this->sleep);

      return;
    }

    vibrateActions::vibrate(this->index, this->sleep);
	}

	void HandleOKCallback() {
		Nan::HandleScope scope;
		v8::Local<v8::Value> argv[] = {
      Nan::Null()
    };
		callback->Call(1, argv);
	}

	void HandleErrorCallback() {
		Nan::HandleScope scope;
		v8::Local<v8::Value> argv[] = {
      Nan::New(this->ErrorMessage()).ToLocalChecked()
    };
		callback->Call(1, argv);
	}
};
