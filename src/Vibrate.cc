#include <nan.h>
#include "windows.h"
#include "xinput.h"
#include "Vibrate.h"

#pragma comment(lib, "XInput.lib")

using namespace std;

NAN_MODULE_INIT(Vibrate::init) {
  Nan::Export(target, "vibrate", Vibrate::vibrate);
  Nan::Export(target, "vibrateAll", Vibrate::vibrateAll);
}

NAN_METHOD(Vibrate::vibrate) {
  int index = Nan::To<int>(info[0]).FromJust()-1;

	if(index < 0 || index > XUSER_MAX_COUNT) {
	  return Nan::ThrowTypeError("invalid controller index");
	}

  XINPUT_VIBRATION Vibration;

  ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

  Vibration.wLeftMotorSpeed = 65535;
  Vibration.wRightMotorSpeed = 65535;

  XInputSetState(index, &Vibration);

  Sleep(1000);

  Vibration.wLeftMotorSpeed = 0;
  Vibration.wRightMotorSpeed = 0;

  XInputSetState(index, &Vibration);
}

NAN_METHOD(Vibrate::vibrateAll) {
  XINPUT_VIBRATION Vibration;

  ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

  Vibration.wLeftMotorSpeed = 65535;
  Vibration.wRightMotorSpeed = 65535;

  for(int i = 0; i < XUSER_MAX_COUNT; i++)
  {
    XInputSetState(i, &Vibration);
  }

  Sleep(1000);

  Vibration.wLeftMotorSpeed = 0;
  Vibration.wRightMotorSpeed = 0;

  for(int i = 0; i < XUSER_MAX_COUNT; i++)
  {
    XInputSetState(i, &Vibration);
  }
}