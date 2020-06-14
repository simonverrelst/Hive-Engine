#include "HivePCH.h"
#include "EdgeCollider.h"
#include "HiveScene/GameObject.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "HiveHelpers/Logger.h"

Hive::EdgeCollider::EdgeCollider(const ColliderSettings& settings, const glm::vec2& offset, float radius)
	:ColliderComponent(settings)
	,m_LocalPos { offset }
	,m_Radius {radius}
{

}

void Hive::EdgeCollider::Start()
{
	const RigidBodyComponent* pRb = gameObject->GetComponent<RigidBodyComponent>();

	if (!pRb)
	{
		LOG_ENGINE_ERROR("No rigidbody attached to the object you are trying to place a collider component on");
		return;
	}

	b2EdgeShape edgeShape{};

	const auto localPos = ToPhysicsSpace(m_LocalPos);
	const auto radius = m_Radius / Physics::GetInstance().GetPixelPerMeter();

	edgeShape.m_radius = 0;

	b2FixtureDef colliderDef{};
	colliderDef.shape = &edgeShape;
	colliderDef.density = m_ColliderSettings.m_Density;
	colliderDef.restitution = m_ColliderSettings.m_Restitution;
	colliderDef.isSensor = m_ColliderSettings.m_IsTrigger;
	colliderDef.userData = this;


	m_pFixture = pRb->GetBody()->CreateFixture(&colliderDef);
}
