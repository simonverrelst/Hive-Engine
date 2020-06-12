#pragma once
#include "SceneManager.h"



namespace Hive
{
	class GameObject;

	class  Scene
	{
	public:
		void Add(GameObject* object);

		virtual void Start() = 0; // Called when scene object is created
		virtual void Update() = 0; // Called on update
		virtual void Render() const = 0; // called on render

		void SceneUpdate();
		void SceneFixedUpdate();
		void SceneRender() const;

		virtual ~Scene() = default;

		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

		const std::string& GetSceneName();

	protected:

		explicit Scene(const std::string & name);


		std::string m_Name;
		std::vector <GameObject* > m_Objects;

		static unsigned int m_IdCounter;
	};
}



