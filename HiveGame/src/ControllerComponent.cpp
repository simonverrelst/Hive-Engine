#include "ControllerComponent.h"
#include "HiveScene/GameObject.h"
#include "HiveHelpers/Logger.h"

ControllerComponent::ControllerComponent()
{

}

ControllerComponent::~ControllerComponent()
{

}

void ControllerComponent::Start()
{
	m_pRigidbody = gameObject->GetComponent<Hive::RigidBodyComponent>();
	if (!m_pRigidbody) LOG_ENGINE_ERROR("Didn't find rigidbody\n");
}


void ControllerComponent::Update()
{
	
	//throw std::logic_error("The method or operation is not implemented.");
}

void ControllerComponent::FixedUpdate()
{

	//throw std::logic_error("The method or operation is not implemented.");
}

