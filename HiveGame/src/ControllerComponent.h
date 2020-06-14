#pragma once
#include "HiveComponents/Component.h"
#include "HiveComponents/RigidBodyComponent.h"
#include "HiveHelpers/Structs.h"

#pragma warning( push )
#pragma warning( disable : 4201)
#include "glm/vec2.hpp"
#pragma warning( pop ) 

namespace Hive
{
	class AnimatedSprite;
	class RigidBodyComponent;
}

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

	void OnCollisionEnter2D(const Hive::Collision& collision) override;

	Hive::RigidBodyComponent* m_pRigidbody;

	glm::vec2 m_Velocity{ };


	Hive::AnimatedSprite* m_pAnimatedSprite;
};

