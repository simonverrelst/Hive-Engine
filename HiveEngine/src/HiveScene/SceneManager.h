#pragma once
#include "HiveHelpers/Singleton.h"
#include <string>
#include <vector>



namespace Hive 
{
	class Scene;
	class  SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene* AddScene(Scene* sceneObj, bool setActive);
		void SetActiveScene(const std::string & name);

		void Update();
		void FixedUpdate();
		void Render();

		void Destroy();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<Scene*> m_Scenes;
		Scene*  m_ActiveScene;

		
	};
}



