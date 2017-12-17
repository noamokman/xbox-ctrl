#include <nan.h>
#include "windows.h"
#include "xinput.h"
#include "Off.h"

#pragma comment(lib, "XInput.lib")

using namespace std;

typedef int (*PowerOffController)(int);

NAN_MODULE_INIT(Off::init) {
  Nan::Export(target, "off", Off::off);
  Nan::Export(target, "offAll", Off::offAll);
}

NAN_METHOD(Off::off) {
  int index = Nan::To<int>(info[0]).FromJust()-1;

	if(index < 0 || index > XUSER_MAX_COUNT) {
	  return Nan::ThrowTypeError("invalid controller index");
	}

  HINSTANCE hXInputDLL = LoadLibraryA("XInput1_3.dll");

	if (hXInputDLL == NULL) {
	  return Nan::ThrowError("failed to load xinput dll");
	}

  XINPUT_STATE state;
  memset(&state, 0, sizeof(XINPUT_STATE));

  if(XInputGetState(index, &state) == ERROR_SUCCESS)
  {
    PowerOffController(*GetProcAddress(hXInputDLL, (LPCSTR) 103))(index);
  }

  ZeroMemory(&state, sizeof(XINPUT_STATE));

	FreeLibrary(hXInputDLL);
}

NAN_METHOD(Off::offAll) {
  HINSTANCE hXInputDLL = LoadLibraryA("XInput1_3.dll");

	if (hXInputDLL == NULL) {
	  return Nan::ThrowError("failed to load xinput dll");
	}

	for(int i = 0; i < XUSER_MAX_COUNT; i++)
	{
		XINPUT_STATE state;
		memset(&state, 0, sizeof(XINPUT_STATE));

		if(XInputGetState(i, &state) == ERROR_SUCCESS)
		{
			PowerOffController(*GetProcAddress(hXInputDLL, (LPCSTR) 103))(i);
		}

		ZeroMemory(&state, sizeof(XINPUT_STATE));
	}

	FreeLibrary(hXInputDLL);
}