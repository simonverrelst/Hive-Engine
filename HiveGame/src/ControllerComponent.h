#pragma once
#include "HiveComponents/Component.h"
#include "HiveComponents/RigidBodyComponent.h"

#pragma warning( push )
#pragma warning( disable : 4201)
#include "glm/vec2.hpp"
#pragma warning( pop ) 

class ControllerComponent :
	public Hive::Component
{
public:
	ControllerComponent();
	virtual ~ControllerComponent();
protected:
	virtual void Start() override;

	virtual void Update() override;

	virtual void FixedUpdate() override;

	float m_WalkSpeed = 450.f;
	Hive::RigidBodyComponent* m_pRigidbody;

	glm::vec2 m_Velocity{ };



};

