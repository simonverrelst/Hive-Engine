#pragma once
#include "Singleton.h"
#include "SDL2/SDL.h"


namespace Hive 
{
	class  Time final : public Singleton<Time>
	{

	public:
		 ~Time() {};

		void Init();
		void Update();

		float GetElapsedTime() { return m_ElapsedSec; };
		float GetTotalTime() { return m_TotalTime; };
		size_t GetFPS() { return m_FPS; };
	private:

		float m_FPSTimer = 0;
		size_t m_FPSCounter = 0;
		size_t m_FPS = 0;
		
		float m_ElapsedSec = 0.f;
		float m_StartTime = 0.f;
		float m_TotalTime = 0.f;
		float m_SecondsPerFrame = 0.f;

		long long m_PreviousTime = 0;
		long long m_CurrentTime = 0;
		long long m_InitTime = 0;

		bool m_Paused = false;

	};
}

