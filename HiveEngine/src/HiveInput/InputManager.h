#pragma once
#include "../HiveHelpers/Singleton.h"

namespace Hive 
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool IsKeyPressed(SDL_Scancode scancode);
		bool IsKeyHeld(SDL_Scancode scancode);

	};
}



