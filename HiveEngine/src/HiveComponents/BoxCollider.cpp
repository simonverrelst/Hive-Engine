#include "HivePCH.h"
#include "BoxCollider.h"
#include "RigidBodyComponent.h"

Hive::BoxCollider::BoxCollider(const ColliderSettings& settings, const glm::vec2& boxPos, const glm::vec2& boxSize)
	:ColliderComponent(settings)
	,m_BoxPos{boxPos}
	,m_BoxSize{boxSize}
{
	
}

void Hive::BoxCollider::Start()
{
	
}
