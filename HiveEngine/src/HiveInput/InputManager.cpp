#include "HivePCH.h"
#include "InputManager.h"


void Hive::InputManager::Init()
{
	m_KeyState.resize(SDL_Scancode::SDL_NUM_SCANCODES);
}


bool Hive::InputManager::IsKeyPressed(SDL_Scancode scancode)
{
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	return bool(state[scancode]);
}

bool Hive::InputManager::IsKeyHeld(SDL_Scancode scancode)
{
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	m_KeyState[scancode] = bool(state[scancode]);

	

	return bool(state[scancode]);
}

bool Hive::InputManager::IsGamepadButton()
{


}
