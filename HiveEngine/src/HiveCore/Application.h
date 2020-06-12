#pragma once

#include "Core.h"
#include <SDL2/SDL.h>
namespace Hive {

	class  Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Init();

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		void Run();

		void HandleEvent();


	protected:
		void InternalUpdate();
		void InternalRender();
		void InternalPhysicsUpdate();

		bool EngineRunning;
		SDL_Window* m_Window;
	
	};

	Application* CreateApplication();
}



