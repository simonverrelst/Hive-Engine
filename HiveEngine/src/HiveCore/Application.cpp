#include "HivePCH.h"
#include "Application.h"
#include "HiveHelpers/Time.h"
#include "HiveRender/Renderer.h"
#include "HiveHelpers/Logger.h"
#include "HiveInput/InputManager.h"
#include "HiveScene/SceneManager.h"
#include "HivePhysics/Physics.h"

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
		Physics::GetInstance().Init(PhysicsSettings());
		InputManager::GetInstance().Init();
	}

	void Application::Run()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0)
		{
			LOG_ENGINE_ERROR("SDL FAILED TO INITIALIZE");
		}

		m_Window = SDL_CreateWindow(
			"Hive Engine",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640,
			560,
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

			HandleInput();

			InternalUpdate();

			InternalPhysicsUpdate();

			InternalLateUpdate();

			InternalRender();

		}

		Renderer::GetInstance().Destroy();
		Physics::GetInstance().Destroy();
		SceneManager::GetInstance().Destroy();


		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
		SDL_Quit();
	}
	void Application::HandleInput()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			EngineRunning = false;
			break;
		}

		InputManager::GetInstance().Update();
	}

	void Application::InternalUpdate()
	{
		SceneManager::GetInstance().Update();

		Update();
	}
	void Application::InternalRender()
	{
		Renderer::GetInstance().RenderStart();

		SceneManager::GetInstance().Render();

		Render();

#ifdef _DEBUG
		Physics::GetInstance().DebugRender();
#endif // _DEBUG

		Renderer::GetInstance().RenderEnd();
	}

	void Application::InternalPhysicsUpdate()
	{
		float elapsedSec = Time::GetInstance().GetElapsedTime();
		const float fixedStep = Physics::GetInstance().GetFixedTimeStep();

		if (elapsedSec > 0.25f)
			elapsedSec = 0.25f;

		Time::GetInstance().m_FrameTimeCounter += elapsedSec;

		while (Time::GetInstance().m_FrameTimeCounter >= fixedStep)
		{
			SceneManager::GetInstance().FixedUpdate();

			Physics::GetInstance().Step();

		
			Time::GetInstance().m_FrameTimeCounter -= fixedStep;
		}
	}

	void Application::InternalLateUpdate()
	{
		InputManager::GetInstance().UpdatePreviousState();
	}
}