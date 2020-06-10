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
	,m_Objects{}
{
}

void Hive::Scene::SceneUpdate()
{
	for (const auto& object : m_Objects)
		object->Update();
}

void Hive::Scene::SceneRender() const
{
	for (const auto& object : m_Objects)
		object->Render();
}

void Hive::Scene::Add(GameObject* object)
{
	object->Start();
	m_Objects.push_back(object);
}



