#include "HivePCH.h"
#include "Scene.h"
#include "GameObject.h"


unsigned int Hive::Scene::m_IdCounter = 0;

const std::string& Hive::Scene::GetSceneName()
{
	return m_Name;
}

Hive::Scene::Scene(const std::string & name)
	: m_Name(name) 
	,m_pObjects{}
{
}

void Hive::Scene::SceneUpdate()
{
	for (const auto& object : m_pObjects)
		object->Update();
}

void Hive::Scene::SceneFixedUpdate()
{
	for (const auto& object : m_pObjects)
		object->FixedUpdate();
}

void Hive::Scene::SceneRender() const
{
	for (const auto& object : m_pObjects)
		object->Render();
}

Hive::Scene::~Scene()
{
	for (GameObject * object : m_pObjects)
	{
		SafeDelete(object);
	}
}

void Hive::Scene::Add(GameObject* object)
{
	object->Start();
	m_pObjects.push_back(object);
}



