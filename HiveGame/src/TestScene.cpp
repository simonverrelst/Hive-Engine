#include "TestScene.h"
#include <HiveScene/GameObject.h>
#include <HiveComponents/SpriteComponent.h>
#include <HiveComponents/TextComponent.h>
#include <HiveRender/Font.h>
#include <HiveComponents/TransformComponent.h>
#include <HiveComponents/RigidBodyComponent.h>
#include <HiveComponents/BoxCollider.h>
#include "LevelManager.h"
#include <HiveInput/InputManager.h>
#include "PlayerComponent.h"
#include <HiveInput/PlayerManager.h>



TestScene::TestScene()
	:Scene("TestScene")
	,m_pLevelManager{}
{

}

void TestScene::Start()
{


	m_pLevelManager = new LevelManager("Resources/Data/LevelData.dat","Resources/Data/EnemyData.dat");

	Hive::GameObject* levelManager = new Hive::GameObject();
	levelManager->AddComponent(m_pLevelManager);
	Add(levelManager);

	m_pLevelManager->AddLevelToScene();

	//auto gameObject = new Hive::GameObject();

	//gameObject->GetTransform()->SetPosition(100, 200);
	//gameObject->GetTransform()->SetRotation(25, true);
	//gameObject->GetTransform()->SetScale({ 1.f,1.f });

	//gameObject->AddComponent(new Hive::SpriteComponent("Sprites/logo.png"));
	//gameObject->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2BodyType::b2_dynamicBody)));
	//gameObject->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings(), {}, {208,65}));
	//Add(gameObject);

	auto gameObject = new Hive::GameObject();

	gameObject->GetTransform()->SetPosition(100, 200);
	gameObject->GetTransform()->SetRotation(25, true);
	gameObject->GetTransform()->SetScale({ 1.f,1.f });

	gameObject->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2BodyType::b2_dynamicBody, false, true, 1.f)));
	gameObject->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings(0.05f,0.f,false,1.f), {}, {10,10}));
	gameObject->AddComponent(new PlayerComponent(Hive::PlayerManager::GetInstance().GetPlayerController(0)));
	gameObject->AddComponent(new Hive::SpriteComponent("Sprites/heroBlue.png"));

	Add(gameObject);

	//auto gameObject2 = new Hive::GameObject();

	//gameObject2->GetTransform()->SetPosition(10, 50);

	//gameObject2->AddComponent(new Hive::TextComponent("Text", new Hive::Font("Resources/Fonts/bubblebobble.ttf", 30)));
	//Add(gameObject2);
	

}

void TestScene::Update()
{

	if (Hive::InputManager::GetInstance().IsKeyPressed(SDL_SCANCODE_F)) m_pLevelManager->NextLevel();
	//if (Hive::InputManager::GetInstance().IsKeyDown(SDL_SCANCODE_G)) m_pLevelManager->NextLevel();
	//if (Hive::InputManager::GetInstance().IsKeyReleased(SDL_SCANCODE_H)) m_pLevelManager->NextLevel();

	//if (Hive::InputManager::GetInstance().IsMouseButtonDown(Hive::left)) m_pLevelManager->NextLevel();
	//if (Hive::InputManager::GetInstance().IsMouseButtonPressed(Hive::right)) m_pLevelManager->NextLevel();
	//if (Hive::InputManager::GetInstance().IsMouseButtonReleased(Hive::middle)) m_pLevelManager->NextLevel();
}

void TestScene::Render() const
{

}