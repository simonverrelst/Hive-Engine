#include "HivePCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include "HiveHelpers/Logger.h"

namespace Hive 
{
	void SceneManager::Update()
	{
		if (m_ActiveScene) {
			m_ActiveScene->SceneUpdate();
			m_ActiveScene->Update();
		}
	}


	void SceneManager::FixedUpdate()
	{
		if (m_ActiveScene) {
			m_ActiveScene->SceneFixedUpdate();
		}
	}


	void SceneManager::Render()
	{
		if (m_ActiveScene) {
			m_ActiveScene->SceneRender();
			m_ActiveScene->Render();
		}
	}

	Scene* SceneManager::AddScene(Scene * sceneObj,bool setActive)
	{
		m_Scenes.push_back(sceneObj);
		if (setActive) {
			SetActiveScene(sceneObj->GetSceneName());
		}
		
		return sceneObj;
	}

	void SceneManager::SetActiveScene(const std::string& name)
	{
		for (const auto& scene : m_Scenes)
		{
			if (scene->GetSceneName() == name) {
				m_ActiveScene = scene;
				m_ActiveScene->Start();
				return;
			}
		}
		LOG_ENGINE_WARN("Scene not found with name {0}", name);
	}

}

