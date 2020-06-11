#include "HiveGame.h"

#include "TestScene.h"


HiveGame::HiveGame()
{

}

HiveGame::~HiveGame()
{

}


void HiveGame::Start()
{
	Hive::ResourceManager::GetInstance().Init("Resources/");

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