#include "HivePCH.h"
#include "HivePhysics/Physics.h"
#include "RigidBodyComponent.h"
#include "Box2D/Box2D.h"
#include "HiveScene/GameObject.h"
#include "TransformComponent.h"
#include "HiveHelpers/Utils.h"


Hive::RigidBodyComponent::RigidBodyComponent(const RigidBodySettings& settings)
	:m_Settings{ settings }
	, m_pBody{}
{
}

void Hive::RigidBodyComponent::Start()
{

	const auto pos = ToPhysicsSpace(gameObject->GetTransform()->GetPosition());
	b2BodyDef definition{};
	definition.userData = gameObject;
	definition.gravityScale = m_Settings.m_GravityMultiplier;
	definition.bullet = m_Settings.m_IsBullet;
	definition.fixedRotation = m_Settings.m_FixedRotation;
	definition.type = m_Settings.m_BodyType;
	definition.enabled = true;
	definition.position.Set(pos.x, pos.y);
	definition.allowSleep = false;


	m_pBody = Physics::GetInstance().GetPhysicsWorld()->CreateBody(&definition);

	b2MassData mass{};
	mass.mass = 1.f;

	m_pBody->SetMassData(&mass);


}

void Hive::RigidBodyComponent::FixedUpdate()
{
	const auto transform = m_pBody->GetTransform();
	float angle = transform.q.GetAngle();
	gameObject->GetTransform()->SetPosition(ToPixelSpace(transform.p));
	gameObject->GetTransform()->SetRotation(angle);
}
