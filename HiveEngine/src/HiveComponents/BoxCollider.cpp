#include "HivePCH.h"
#include "BoxCollider.h"
#include "HiveScene/GameObject.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "HiveHelpers/Logger.h"




Hive::BoxCollider::BoxCollider(const ColliderSettings& settings, const glm::vec2& offset, const glm::vec2& boxSize)
	:ColliderComponent(settings)
	,m_BoxPos{ offset }
	,m_BoxSize{boxSize}
{
	
}

void Hive::BoxCollider::Start()
{
	const RigidBodyComponent* pRb = gameObject->GetComponent<RigidBodyComponent>();

	if (!pRb)
	{
		LOG_ENGINE_ERROR("No rigidbody attached to the object you are trying to place a collider component on");
		return;
	}

	b2PolygonShape boxShape{};

	const auto boxPos = ToPhysicsSpace(m_BoxPos);
	const auto boxSize = ToPhysicsSpace(m_BoxSize * gameObject->GetTransform()->GetScale());

	boxShape.SetAsBox(boxSize.x, boxSize.y, ToVectorBox2D(boxPos), gameObject->GetTransform()->GetRotation());

	b2FixtureDef colliderDef{};
	colliderDef.shape = &boxShape;
	colliderDef.density = m_ColliderSettings.m_Density;
	colliderDef.restitution = m_ColliderSettings.m_Restitution;
	colliderDef.isSensor = m_ColliderSettings.m_IsTrigger;
	colliderDef.userData = this;
	

	m_pFixture = pRb->GetBody()->CreateFixture(&colliderDef);

}
