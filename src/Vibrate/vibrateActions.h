#include "windows.h"
#include "xinput.h"

#pragma comment(lib, "XInput.lib")

namespace vibrateActions
{
  XINPUT_VIBRATION getVibration(bool on);
  void vibrate(int index, int sleep);
  void vibrateAll(int sleep);
}