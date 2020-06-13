#pragma once

#include "HiveHelpers/Structs.h"

namespace Hive
{
	
	class Component;
	class TransformComponent;
	class Scene;

	class  GameObject
	{
	public:

		GameObject();
		virtual ~GameObject();

		void Start();
		void Update();
		void FixedUpdate();
		void Render() const;

		void OnTriggerEnter2D(const Collision & trigger);
		void OnTriggerExit2D(const Collision& trigger);

		void OnCollisionEnter2D(const Collision& collision);
		void OnCollisionExit2D(const Collision& collision);


		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void AddComponent(Component * comp);
		TransformComponent* GetTransform() { return m_Transform; };
		Scene* GetScene() { return m_pScene; }

		template <class T>
		T* GetComponent()
		{
			const type_info& ti = typeid(T);
			for (auto* component : m_Components)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}
			return nullptr;
		}

		Scene* m_pScene;

		void SetActive(bool state);
		bool IsActive() const { return m_IsActive; }

	protected:
		void OnEnable();
		void OnDisable();


	private:
		std::vector<Component *> m_Components;

		TransformComponent * m_Transform;

		bool m_IsActive{ true };

	};
}




