#pragma once
#include "../HiveHelpers/Singleton.h"
#include <SDL2/SDL_scancode.h>

namespace Hive 
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		void Init();

		bool IsKeyPressed(SDL_Scancode scancode);
		bool IsKeyHeld(SDL_Scancode scancode);
		bool IsGamepadButton();
	private:
		std::vector<bool> m_KeyState;
	};
}



