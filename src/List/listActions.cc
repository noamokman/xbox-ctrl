#include "listActions.h"

namespace listActions
{
  std::vector<int> list() {
    std::vector<int> vec;

  	for(int i = 0; i < XUSER_MAX_COUNT; i++)
  	{
  		XINPUT_STATE state;
  		memset(&state, 0, sizeof(XINPUT_STATE));

  		if(XInputGetState(i, &state) == ERROR_SUCCESS)
  		{
  		  vec.push_back(i);
  		}

  		ZeroMemory(&state, sizeof(XINPUT_STATE));
  	}

  	return vec;
  }
}