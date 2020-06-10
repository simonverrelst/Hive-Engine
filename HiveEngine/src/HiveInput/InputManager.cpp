#include "HivePCH.h"
#include "InputManager.h"

bool Hive::InputManager::IsKeyPressed(SDL_Scancode scancode)
{
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	return bool(state[scancode]);
}

bool Hive::InputManager::IsKeyHeld(SDL_Scancode scancode)
{
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	return bool(state[scancode]);
}
