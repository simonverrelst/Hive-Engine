#include "HivePCH.h"
#include "HivePhysics/Physics.h"
#include "RigidBodyComponent.h"


Hive::RigidBodyComponent::RigidBodyComponent(const RigidBodySettings & settings)
	:m_Settings{settings}
	,m_pBody{}
{
}

void Hive::RigidBodyComponent::Start()
{
	b2BodyDef definition{};
	definition.userData = gameObject;
	definition.gravityScale = m_Settings.gravityMultiplier;
	definition.bullet = m_Settings.isBullet;
	definition.fixedRotation = m_Settings.fixedRotation;
	definition.type = m_Settings.bodyType;
	m_pBody = new b2Body(&definition, Physics::GetInstance().GetPhysicsWorld());
}

void Hive::RigidBodyComponent::Update()
{

}
