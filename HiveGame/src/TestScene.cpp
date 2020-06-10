#include "TestScene.h"
#include <HiveScene/GameObject.h>


TestScene::TestScene()
	:Scene("TestScene")
{

}

void TestScene::Start()
{
	auto gameObject = new Hive::GameObject();

	Add(gameObject);
}

void TestScene::Update()
{

}

void TestScene::Render() const
{

}