#include "HivePCH.h"
#include "CircleCollider.h"
#include "HiveScene/GameObject.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "HiveHelpers/Logger.h"


Hive::CircleCollider::CircleCollider(const ColliderSettings& settings, const glm::vec2& offset, float radius)
	:ColliderComponent(settings)
	,m_LocalPos{ offset }
	,m_Radius {radius}
{

}

void Hive::CircleCollider::Start()
{
	const RigidBodyComponent* pRb = gameObject->GetComponent<RigidBodyComponent>();

	if (!pRb)
	{
		LOG_ENGINE_ERROR("No rigidbody attached to the object you are trying to place a collider component on");
		return;
	}

	b2CircleShape circleShape{};

	const auto localPos = ToPhysicsSpace(m_LocalPos);
	const auto radius = m_Radius / Physics::GetInstance().GetPixelPerMeter();

	circleShape.m_p.Set(localPos.x, localPos.y);

	b2FixtureDef colliderDef{};
	colliderDef.shape = &circleShape;
	colliderDef.density = m_ColliderSettings.m_Density;
	colliderDef.restitution = m_ColliderSettings.m_Restitution;
	colliderDef.isSensor = m_ColliderSettings.m_IsTrigger;
	colliderDef.userData = this;


	m_pFixture = pRb->GetBody()->CreateFixture(&colliderDef);
}

