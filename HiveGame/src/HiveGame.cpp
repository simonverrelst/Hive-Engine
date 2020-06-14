#include "HiveGame.h"

#include "TestScene.h"
#include "ActionMappings.h"


HiveGame::HiveGame()
{

}

HiveGame::~HiveGame()
{

}


void HiveGame::Start()
{
	Hive::PlayerManager::GetInstance().Init(2);

	Hive::ResourceManager::GetInstance().Init("Resources/");

	Hive::SceneManager::GetInstance().AddScene(new TestScene(),true);


	Hive::PlayerController* controller = Hive::PlayerManager::GetInstance().GetPlayerController(0);
	controller->AddCommand(PlayerControls::jump, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_W, Hive::ButtonPressType::OnPress)));
	controller->AddCommand(PlayerControls::right, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_D, Hive::ButtonPressType::OnHold)));
	controller->AddCommand(PlayerControls::left, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_A, Hive::ButtonPressType::OnHold)));
	controller->AddCommand(PlayerControls::shoot, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_SPACE, Hive::ButtonPressType::OnHold)));

	controller = Hive::PlayerManager::GetInstance().GetPlayerController(1);
	controller->AddCommand(PlayerControls::jump, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_UP, Hive::ButtonPressType::OnPress)));
	controller->AddCommand(PlayerControls::right, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_RIGHT, Hive::ButtonPressType::OnHold)));
	controller->AddCommand(PlayerControls::left, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_LEFT, Hive::ButtonPressType::OnHold)));
	controller->AddCommand(PlayerControls::shoot, new Hive::KeyboardInput(Hive::Action(SDL_SCANCODE_RSHIFT, Hive::ButtonPressType::OnHold)));



}

void HiveGame::Update()
{
	#pragma region testCode
	//float elapsedSec = Hive::Time::GetInstance().GetElapsedTime();
	//LOG_INFO("elapsed sec = {0}", elapsedSec);

	//Hive::PlayerController* controller = Hive::PlayerManager::GetInstance().GetPlayerController(0);

	//if (controller->WasActionPerformed(0))
	//	LOG_INFO("R");

	//if (controller->WasActionPerformed(1))
	//	LOG_INFO("T");

	//if (controller->WasActionPerformed(2))
	//	LOG_INFO("Y");

	//if (controller->WasActionPerformed(3))
	//	LOG_INFO("left");

	//if (controller->WasActionPerformed(4))
	//	LOG_INFO("right");

	//if (controller->WasActionPerformed(5))
	//	LOG_INFO("back");

	#pragma endregion testCode
	

}

void HiveGame::Render()
{

}