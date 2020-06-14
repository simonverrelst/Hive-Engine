#include "HivePCH.h"
#include "InputManager.h"




Hive::InputManager::~InputManager()
{
	delete[] m_PrevKeyState;
	m_PrevKeyState = nullptr;
}


bool Hive::InputManager::IsGamepadButton()
{

	return true;
}

bool Hive::InputManager::IsKeyPressed(SDL_Scancode scancode)
{
	return !m_PrevKeyState[scancode] && m_CurrentKeyState[scancode];
}

bool Hive::InputManager::IsKeyDown(SDL_Scancode scancode)
{
	return m_CurrentKeyState[scancode];
}

bool Hive::InputManager::IsKeyReleased(SDL_Scancode scancode)
{
	return m_PrevKeyState[scancode] && !m_CurrentKeyState[scancode];
}

bool Hive::InputManager::IsMouseButtonDown(MouseButtons mouseButton)
{
	uint32 buttonMask{};

	switch (mouseButton)
	{
	case Hive::left:
		buttonMask = SDL_BUTTON_LMASK;
		break;
	case Hive::right:
		buttonMask = SDL_BUTTON_RMASK;
		break;
	case Hive::middle:
		buttonMask = SDL_BUTTON_MMASK;
		break;
	case Hive::back:
		buttonMask = SDL_BUTTON_X1MASK;
		break;
	case Hive::forward:
		buttonMask = SDL_BUTTON_X2MASK;
		break;
	}

	return (m_MouseState & buttonMask);
}

bool Hive::InputManager::IsMouseButtonPressed(MouseButtons mouseButton)
{
	uint32 buttonMask{};

	switch (mouseButton)
	{
	case Hive::left:
		buttonMask = SDL_BUTTON_LMASK;
		break;
	case Hive::right:
		buttonMask = SDL_BUTTON_RMASK;
		break;
	case Hive::middle:
		buttonMask = SDL_BUTTON_MMASK;
		break;
	case Hive::back:
		buttonMask = SDL_BUTTON_X1MASK;
		break;
	case Hive::forward:
		buttonMask = SDL_BUTTON_X2MASK;
		break;
	}

	return !(m_PrevMouseState & buttonMask) && (m_MouseState & buttonMask);
}

bool Hive::InputManager::IsMouseButtonReleased(MouseButtons mouseButton)
{
	uint32 buttonMask{};

	switch (mouseButton)
	{
	case Hive::left:
		buttonMask = SDL_BUTTON_LMASK;
		break;
	case Hive::right:
		buttonMask = SDL_BUTTON_RMASK;
		break;
	case Hive::middle:
		buttonMask = SDL_BUTTON_MMASK;
		break;
	case Hive::back:
		buttonMask = SDL_BUTTON_X1MASK;
		break;
	case Hive::forward:
		buttonMask = SDL_BUTTON_X2MASK;
		break;
	}

	return (m_PrevMouseState & buttonMask) && !(m_MouseState & buttonMask);
}

glm::vec2 Hive::InputManager::GetMousePos() const
{
	return glm::vec2{ float(m_MouseXPos),float(m_MouseYPos) };
}

void Hive::InputManager::Update()
{
	m_MouseState = SDL_GetMouseState(&m_MouseXPos, &m_MouseYPos);
}

void Hive::InputManager::UpdatePreviousState()
{
	memcpy(m_PrevKeyState, m_CurrentKeyState, m_AmountOfKeys);
	m_PrevMouseState = m_MouseState;

}

void Hive::InputManager::Init()
{
	m_CurrentKeyState = SDL_GetKeyboardState(&m_AmountOfKeys);
	m_PrevKeyState = new uint8[m_AmountOfKeys];
	memcpy(m_PrevKeyState, m_CurrentKeyState, m_AmountOfKeys);
}
