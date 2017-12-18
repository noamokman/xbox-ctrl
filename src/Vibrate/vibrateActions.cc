#include "vibrateActions.h"

namespace vibrateActions
{
  XINPUT_VIBRATION getVibration(bool on) {
    XINPUT_VIBRATION vibration;

    ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

    int speed = on ? 65535 : 0;

    vibration.wLeftMotorSpeed = speed;
    vibration.wRightMotorSpeed = speed;

    return vibration;
  }

  void vibrate(int index, int sleep) {
    XInputSetState(index, &getVibration(true));

    Sleep(sleep);

    XInputSetState(index, &getVibration(false));
  }

  void vibrateAll(int sleep) {
    XINPUT_VIBRATION on = getVibration(true);
    XINPUT_VIBRATION off = getVibration(false);

    for(int i = 0; i < XUSER_MAX_COUNT; i++)
    {
      XInputSetState(i, &on);
    }

    Sleep(sleep);

    for(int i = 0; i < XUSER_MAX_COUNT; i++)
    {
      XInputSetState(i, &off);
    }
  }
}