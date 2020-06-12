#pragma once
#include "Component.h"

#include "Box2D/Box2D.h"

namespace Hive
{
	struct ColliderSettings
	{
		ColliderSettings(float friction = 0.3f, float restitution = 0.f, bool isTrigger = false, float density = 1.f)
			:m_Friction {friction}
			,m_Restitution {restitution}
			,m_IsTrigger{isTrigger}
			,m_Density{density}
		{}

		float m_Density = 1.f;
		float m_Friction = 0.25f;
		float m_Restitution = 0.f;
		bool m_IsTrigger = false;
	};

	class ColliderComponent :
		public Component
	{
	public:
		ColliderComponent(const ColliderSettings& settings)
			:m_ColliderSettings{ settings }
		{}

		b2Fixture* GetCollisionShape() const { return m_pFixture; }

	private:

		b2Fixture* m_pFixture = nullptr;
		ColliderSettings m_ColliderSettings;
	};

}


