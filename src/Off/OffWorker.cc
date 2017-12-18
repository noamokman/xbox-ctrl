#include <nan.h>
#include <string>
#include "offActions.h"

using namespace std;
using namespace offActions;

class OffWorker : public Nan::AsyncWorker {
public:
	int index;

	OffWorker(int index, Nan::Callback *callback)
    : Nan::AsyncWorker(callback) {
    this->index = index;
  }

	void Execute() {
    if(this->index == -1) {
      std::string error = offActions::offAll();

      if(!error.empty()) {
        this->SetErrorMessage(error.c_str());
      }

      return;
    }

    std::string error = offActions::off(this->index);

    if(!error.empty()) {
      this->SetErrorMessage(error.c_str());
    }
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
