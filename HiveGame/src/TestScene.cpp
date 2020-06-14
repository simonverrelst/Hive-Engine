#include "TestScene.h"
#include <HiveScene/GameObject.h>
#include <HiveComponents/SpriteComponent.h>
#include <HiveComponents/TextComponent.h>
#include <HiveRender/Font.h>
#include <HiveComponents/TransformComponent.h>
#include <HiveComponents/RigidBodyComponent.h>
#include <HiveComponents/BoxCollider.h>
#include <HiveComponents/CircleCollider.h>
#include "LevelManager.h"
#include <HiveInput/InputManager.h>
#include "PlayerComponent.h"
#include <HiveInput/PlayerManager.h>
#include <HiveComponents/AnimatedSprite.h>



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

	auto BubCharacter = new Hive::GameObject();

	BubCharacter->GetTransform()->SetPosition(100, 200);
	BubCharacter->GetTransform()->SetScale({ 0.5f,0.5f });

	BubCharacter->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2BodyType::b2_dynamicBody, false, true, 0.75f)));
	BubCharacter->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings(0.1f,0.01f,false,1.f), {}, {20,20}));
	BubCharacter->AddComponent(new Hive::AnimatedSprite("Sprites/heroGreen.png",4,3));
	BubCharacter->AddComponent(new PlayerComponent(Hive::PlayerManager::GetInstance().GetPlayerController(0)));

	Add(BubCharacter);

	auto BobCharacter = new Hive::GameObject();

	BobCharacter->GetTransform()->SetPosition(500, 200);
	BobCharacter->GetTransform()->SetScale({ 0.5f,0.5f });

	BobCharacter->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2BodyType::b2_dynamicBody, false, true, 0.75f)));
	BobCharacter->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings(0.1f, 0.01f, false, 1.f), {}, { 20,20 }));
	BobCharacter->AddComponent(new Hive::AnimatedSprite("Sprites/heroBlue.png", 4, 3));
	BobCharacter->AddComponent(new PlayerComponent(Hive::PlayerManager::GetInstance().GetPlayerController(1)));

	Add(BobCharacter);

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