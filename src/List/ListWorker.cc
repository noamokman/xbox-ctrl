#include <nan.h>
#include "helper.h"
#include "listActions.h"

using namespace helper;
using namespace listActions;

class ListWorker : public Nan::AsyncWorker {
public:
  std::vector<int> list;

	ListWorker(Nan::Callback *callback)
    : Nan::AsyncWorker(callback) {}

	void Execute() {
    this->list = listActions::list();
	}

	void HandleOKCallback() {
		Nan::HandleScope scope;
		v8::Local<v8::Value> argv[] = {
      Nan::Null(),
      vectorToArray(this->list)
    };
		callback->Call(2, argv);
	}

	void HandleErrorCallback() {
		Nan::HandleScope scope;
		v8::Local<v8::Value> argv[] = {
      Nan::New(this->ErrorMessage()).ToLocalChecked()
    };
		callback->Call(1, argv);
	}
};
