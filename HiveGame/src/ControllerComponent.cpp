#include "ControllerComponent.h"
#include "HiveScene/GameObject.h"
#include "HiveHelpers/Logger.h"
#include "HiveComponents/AnimatedSprite.h"
#include "HiveComponents/RigidbodyComponent.h"

ControllerComponent::ControllerComponent()
{

}

ControllerComponent::~ControllerComponent()
{

}

void ControllerComponent::Start()
{
	m_pRigidbody = gameObject->GetComponent<Hive::RigidBodyComponent>();
	if (!m_pRigidbody) LOG_ERROR("Didn't find rigidbody\n");

	m_pAnimatedSprite = gameObject->GetComponent<Hive::AnimatedSprite>();
	if (!m_pAnimatedSprite) LOG_ERROR("Didn't find animated sprite\n");
}


void ControllerComponent::Update()
{
	
	//throw std::logic_error("The method or operation is not implemented.");
}

void ControllerComponent::FixedUpdate()
{

	//throw std::logic_error("The method or operation is not implemented.");
}

