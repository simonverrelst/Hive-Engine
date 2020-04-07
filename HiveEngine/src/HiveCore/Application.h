#pragma once

#include "Core.h"
#include <SDL2/SDL.h>
namespace Hive {

	class HIVEAPI Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Init();

		virtual void Start() = 0;

		void Run();

		void HandleEvent();

		void HandleInput();

		void Update();

		void Render();
	private:
		bool EngineRunning;
		SDL_Window* m_Window;
	};

	Application* CreateApplication();
}



