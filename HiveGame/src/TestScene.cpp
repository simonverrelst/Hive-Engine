#include "TestScene.h"
#include <HiveScene/GameObject.h>
#include <HiveComponents/SpriteComponent.h>
#include <HiveComponents/TextComponent.h>
#include <HiveRender/Font.h>
#include <HiveComponents/TransformComponent.h>
#include <HiveComponents/RigidBodyComponent.h>
#include <HiveComponents/BoxCollider.h>


TestScene::TestScene()
	:Scene("TestScene")
{

}

void TestScene::Start()
{
	auto gameObject = new Hive::GameObject();
	gameObject->AddComponent(new Hive::SpriteComponent("Sprites/logo.png"));
	gameObject->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2BodyType::b2_dynamicBody)));
	gameObject->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings()));
	Add(gameObject);

	gameObject->GetTransform()->SetPosition(100, 200);


	auto gameObject3 = new Hive::GameObject();

	gameObject3->GetTransform()->SetPosition(0, 600);
	gameObject3->GetTransform()->SetScale({ 10,1 });

	gameObject3->AddComponent(new Hive::SpriteComponent("Sprites/logo.png"));
	gameObject3->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2BodyType::b2_staticBody)));
	gameObject3->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings()));

	Add(gameObject3);



	auto gameObject2 = new Hive::GameObject();
	gameObject2->AddComponent(new Hive::TextComponent("Text", new Hive::Font("Resources/Fonts/bubblebobble.ttf", 30)));
	Add(gameObject2);
	gameObject2->GetTransform()->SetPosition(10, 50);

}

void TestScene::Update()
{

}

void TestScene::Render() const
{

}