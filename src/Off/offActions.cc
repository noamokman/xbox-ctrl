#include "offActions.h"
#include "windows.h"
#include "xinput.h"

#pragma comment(lib, "XInput.lib")

typedef int (*PowerOffController)(int);

namespace offActions
{
    std::string off(int index) {
        HINSTANCE hXInputDLL = LoadLibraryA("XInput1_4.dll");

      	if (hXInputDLL == NULL) {
      	  return "failed to load xinput dll";
      	}

        XINPUT_STATE state;
        memset(&state, 0, sizeof(XINPUT_STATE));

        if(XInputGetState(index, &state) == ERROR_SUCCESS)
        {
          PowerOffController(*GetProcAddress(hXInputDLL, (LPCSTR) 103))(index);
        }

        ZeroMemory(&state, sizeof(XINPUT_STATE));

      	FreeLibrary(hXInputDLL);

      	return "";
    }

    std::string offAll() {
      HINSTANCE hXInputDLL = LoadLibraryA("XInput1_4.dll");

      if (hXInputDLL == NULL) {
        return "failed to load xinput dll";
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

      return "";
    }
}