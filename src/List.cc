#include <nan.h>
#include "windows.h"
#include "xinput.h"
#include "List.h"

#pragma comment(lib, "XInput.lib")

using namespace std;

NAN_MODULE_INIT(List::init) {
  Nan::Export(target, "list", List::list);
}

NAN_METHOD(List::list) {
  v8::Local<v8::Array> returnValue = Nan::New<v8::Array>();

  int arrayIndex = 0;

	for(int i = 0; i < XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE state;
		memset(&state, 0, sizeof(XINPUT_STATE));

		if(XInputGetState(i, &state) == ERROR_SUCCESS)
		{
		  returnValue->Set(arrayIndex++, Nan::New<v8::Number>(i+1));
		}

		ZeroMemory(&state, sizeof(XINPUT_STATE));
	}

  info.GetReturnValue().Set(returnValue);
}