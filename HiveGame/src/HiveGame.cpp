#include "HiveGame.h"

#include <glm/vec3.hpp>
#include "TestScene.h"


HiveGame::HiveGame()
{

}

HiveGame::~HiveGame()
{

}


void HiveGame::Start()
{
	LOG_WARN("Test");
	glm::vec3 vectors{ 10,10,10 };
	glm::vec3 vectors2{ 10,10,10 };
	vectors += vectors2;

	

	Hive::SceneManager::GetInstance().AddScene(new TestScene(),true);

}

void HiveGame::Update()
{
	size_t elapsedSec = Hive::Time::GetInstance().GetFPS();
	LOG_INFO("elapsed sec = {0}", elapsedSec);

	if (Hive::InputManager::GetInstance().IsKeyPressed(SDL_SCANCODE_RIGHT))
	{
		LOG_INFO("Key Pressed");
	}
}

void HiveGame::Render()
{
//	throw std::logic_error("The method or operation is not implemented.");
}