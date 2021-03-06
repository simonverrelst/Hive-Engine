#pragma once
#include "HiveHelpers/Structs.h"
#include "HiveCore/Core.h"


namespace Hive
{
	class GameObject;

	class  Component
	{
	public:
		Component() = default;
		virtual ~Component();

		virtual void Start() {};
		virtual void Update() {};
		virtual void FixedUpdate() {};
		virtual void Render() {};

		virtual void OnTriggerEnter2D(const Collision& trigger);
		virtual void OnTriggerExit2D(const Collision& trigger);

		virtual void OnCollisionEnter2D(const Collision& collision);
		virtual void OnCollisionExit2D(const Collision& collision);

		virtual void OnEnable();
		virtual void OnDisable();

		void SetActive(bool state);
		bool IsActive() { return m_IsActive; }
	
		GameObject* gameObject = nullptr;
	private:
		


		bool m_IsActive{ true };
		
	
	};
}




