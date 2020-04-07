#include "HivePCH.h"
#include "Time.h"


void Hive::Time::Init()
{
	m_SecondsPerFrame = 1.0f / float(SDL_GetPerformanceFrequency());
	m_PreviousTime = SDL_GetPerformanceCounter();
	m_InitTime = m_PreviousTime;
}

void Hive::Time::Update()
{
	m_CurrentTime = SDL_GetPerformanceCounter();

	// Calculating elapsed frame time and the total amount of runtime
	m_ElapsedSec = float(((m_CurrentTime - m_PreviousTime) * m_SecondsPerFrame));

	m_PreviousTime = m_CurrentTime;

	m_TotalTime = float((m_CurrentTime - m_InitTime) * m_SecondsPerFrame);

	// Counting amount of frames in a second
	m_FPSTimer += m_ElapsedSec;
	++m_FPSCounter;
	if (m_FPSTimer >= 1.0f) {
		m_FPS = m_FPSCounter;
		m_FPSCounter = 0;
		m_FPSTimer -= 1.0f;
	}
}
