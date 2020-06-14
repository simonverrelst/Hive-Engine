#include "PlayerComponent.h"
#include "HiveInput/PlayerInput.h"
#include "HiveHelpers/Time.h"
#include "HiveHelpers/Utils.h"
#include "HiveHelpers/Structs.h"
#include "HiveComponents/AnimatedSprite.h"


PlayerComponent::PlayerComponent(Hive::PlayerController* controller)
	: m_pController{ controller }
{

}

void PlayerComponent::Start()
{
	ControllerComponent::Start();

	m_WalkSpeed = 1500;

	Hive::AnimationData * walk{new Hive::AnimationData()};
	walk->startFrame = 0;
	walk->endFrame = 2;
	walk->frameTime = 0.2f;

	m_pAnimatedSprite->AddAnimation(walk);
	m_pAnimatedSprite->SetAnimation(0);
	m_pAnimatedSprite->Play();
	
}

void PlayerComponent::Update()
{
	ControllerComponent::Update();

	glm::vec2 input{};
	

	if(m_pController->WasActionPerformed(PlayerControls::left))
		input.x = -1.f;
	if(m_pController->WasActionPerformed(PlayerControls::right)) 
		input.x = 1.f;
	if(m_pController->WasActionPerformed(PlayerControls::jump)) 
		input.y = -1.f;
	if (m_pController->WasActionPerformed(PlayerControls::shoot)) {}

	float elapsedTime = Hive::Time::GetInstance().GetElapsedTime();

	m_Velocity.x = input.x * m_WalkSpeed * elapsedTime;
	m_Velocity.y = input.y * m_JumpSpeed * elapsedTime;

	if (input.x < 0) m_pAnimatedSprite->SetFlip(true);
	if (input.x > 0) m_pAnimatedSprite->SetFlip(false);

	m_pRigidbody->GetBody()->SetLinearDamping(0.3f);
}

void PlayerComponent::FixedUpdate()
{
	ControllerComponent::FixedUpdate();

	b2Body* body =  m_pRigidbody->GetBody();

	b2Vec2 vel = body->GetLinearVelocity();

	glm::vec2 velocityPixelSpace = Hive::ToPixelSpace(vel);

	glm::vec2 velocityChange = m_Velocity - velocityPixelSpace;
	velocityChange *= body->GetMass();

	body->ApplyLinearImpulseToCenter({ Hive::ToPhysicsSpace(velocityChange.x) ,0.f}, true);
	body->ApplyLinearImpulseToCenter({ 0 , Hive::ToPhysicsSpace(m_Velocity.y) }, true);

}
