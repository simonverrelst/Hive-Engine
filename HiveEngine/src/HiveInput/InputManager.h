#pragma once
#include "../HiveHelpers/Singleton.h"
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_mouse.h>

namespace Hive 
{
	enum MouseButtons
	{
		left,
		right,
		middle,
		back,
		forward
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		virtual ~InputManager();
		void Init();

		void Update();

		bool IsKeyDown(SDL_Scancode scancode);
		bool IsKeyPressed(SDL_Scancode scancode);
		bool IsKeyReleased(SDL_Scancode scancode);

		bool IsMouseButtonDown(MouseButtons mouseButton);
		bool IsMouseButtonPressed(MouseButtons mouseButton);
		bool IsMouseButtonReleased(MouseButtons mouseButton);

		glm::vec2 GetMousePos() const;

		bool IsGamepadButton();
		void UpdatePreviousState();
	private:
		uint8* m_PrevKeyState;
		const uint8* m_CurrentKeyState;

		uint32 m_PrevMouseState;
		uint32 m_MouseState;

		int m_MouseXPos;
		int m_MouseYPos;

		int m_AmountOfKeys;

	};
}



