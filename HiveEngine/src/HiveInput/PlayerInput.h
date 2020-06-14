#pragma once
#include "SDL2/SDL_scancode.h"
#include "InputManager.h"
#include <map>

namespace Hive
{
	enum ButtonPressType 
	{
		OnHold,
		OnRelease,
		OnPress,
	};

	struct Action
	{
		Action(SDL_Scancode key, ButtonPressType pressType)
			:keyboardKey { key }
			,buttonPressType {pressType}
			,mouseKey {}
		{}

		Action(MouseButtons mouseButton, ButtonPressType pressType)
			:keyboardKey{}
			, buttonPressType{ pressType }
			, mouseKey{ mouseButton }
		{}

		SDL_Scancode keyboardKey;
		MouseButtons mouseKey;
		ButtonPressType buttonPressType;
	};

	class Command
	{
		public:
			Command(const Action& action) : m_MappedAction{ action } {};
			virtual ~Command() = default;
			virtual bool Execute() = 0;
		protected:
			Action m_MappedAction;
	};

	class KeyboardInput final : public Command
	{
		public:
			KeyboardInput(const Action & action) : Command{ action } {};
			virtual ~KeyboardInput() = default;

			virtual bool Execute() override
			{
				switch (m_MappedAction.buttonPressType)
				{
				case Hive::ButtonPressType::OnHold :
					return InputManager::GetInstance().IsKeyDown(m_MappedAction.keyboardKey);
					break;
				case Hive::ButtonPressType::OnPress :
					return InputManager::GetInstance().IsKeyPressed(m_MappedAction.keyboardKey);
					break;
				case Hive::ButtonPressType::OnRelease :
					return InputManager::GetInstance().IsKeyReleased(m_MappedAction.keyboardKey);
					break;
				}		
				return false;
			}
	};

	class MouseInput final : public Command 
	{
		public:
			MouseInput(const Action & action) : Command{ action } {};
			virtual ~MouseInput() = default;

			virtual bool Execute() override
			{
				switch (m_MappedAction.buttonPressType)
				{
				case Hive::ButtonPressType::OnHold:
					return InputManager::GetInstance().IsMouseButtonDown(m_MappedAction.mouseKey);
					break;
				case Hive::ButtonPressType::OnPress:
					return InputManager::GetInstance().IsMouseButtonPressed(m_MappedAction.mouseKey);
					break;
				case Hive::ButtonPressType::OnRelease:
					return InputManager::GetInstance().IsMouseButtonReleased(m_MappedAction.mouseKey);
					break;
				}
				return false;
			}
	};


	class PlayerController
	{
	public:
		PlayerController(size_t playerID);
		~PlayerController();

		void AddCommand(size_t actionID,  Command * command);
		bool WasActionPerformed(size_t actionID);

	private:
		size_t m_PlayerID;
		std::map<size_t, Command*> m_PlayerActions;
	};
}



