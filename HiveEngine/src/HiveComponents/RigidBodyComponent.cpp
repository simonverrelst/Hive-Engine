#include "HivePCH.h"
#include "HivePhysics/Physics.h"
#include "RigidBodyComponent.h"
#include "Box2D/Box2D.h"
#include "HiveScene/GameObject.h"
#include "TransformComponent.h"



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
	definition.position = ToVectorBox2D(pos);
	definition.allowSleep = true;


	m_pBody = Physics::GetInstance().GetPhysicsWorld()->CreateBody(&definition);

	

	b2MassData mass{};
	mass.mass = 1.f;

	m_pBody->SetMassData(&mass);
}

void Hive::RigidBodyComponent::FixedUpdate()
{
	m_pUpdatingObject = true;

	TransformComponent* pTrans = gameObject->GetTransform();

	b2BodyType type = m_pBody->GetType();
	switch (type)
	{
	case b2_staticBody:
		m_pBody->SetTransform(ToVectorBox2D(ToPhysicsSpace(pTrans->GetPosition())), pTrans->GetRotation());
		break;
	case b2_kinematicBody:
		break;
	case b2_dynamicBody:
		const auto transform = m_pBody->GetTransform();

		float angle = transform.q.GetAngle();
		pTrans->SetPosition(ToPixelSpace(transform.p));
		pTrans->SetRotation(angle, false);
		break;
	}	
	m_pUpdatingObject = false;
}

Hive::RigidBodyComponent::~RigidBodyComponent()
{

}

void Hive::RigidBodyComponent::Translate(const glm::vec2& position)
{
	m_pBody->SetTransform(ToVectorBox2D(ToPhysicsSpace(position)), m_pBody->GetAngle());
}

void Hive::RigidBodyComponent::Rotate(float rotation)
{
	m_pBody->SetTransform(m_pBody->GetPosition(), rotation);
}

