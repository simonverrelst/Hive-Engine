#include "HivePCH.h"
#include "Application.h"
#include "HiveHelpers/Time.h"
#include "HiveRender/Renderer.h"
#include "HiveHelpers/Logger.h"
#include "HiveInput/InputManager.h"
#include "HiveScene/SceneManager.h"

namespace Hive {

	Application::Application()
		: EngineRunning{true}
	{
		Init();
	}

	Application::~Application()
	{
	}

	void Application::Init()
	{
		Time::GetInstance().Init();
	}

	void Application::Run()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			LOG_ENGINE_ERROR("SDL FAILED TO INITIALIZE");
		}

		m_Window = SDL_CreateWindow(
			"Hive Engine",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1280,
			720,
			SDL_WINDOW_OPENGL
		);
		if (m_Window == nullptr)
		{
			LOG_ENGINE_ERROR("SDL WINDOW NULLPTR");
		}

		Renderer::GetInstance().Init(m_Window);

		Start();

		while (EngineRunning)
		{
			Time::GetInstance().Update();

			HandleEvent();

			InternalUpdate();


			InternalRender();

		}

		Renderer::GetInstance().Destroy();
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
		SDL_Quit();
	}
	void Application::HandleEvent()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			EngineRunning = false;
			break;
		}
	}

	void Application::InternalUpdate()
	{

		SceneManager::GetInstance().Update();

		Update();
	}
	void Application::InternalRender()
	{


		Renderer::GetInstance().Render();
		Render();
	}
}