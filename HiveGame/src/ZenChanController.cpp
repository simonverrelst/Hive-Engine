#include "ZenChanController.h"
#include "HiveHelpers/Time.h"
#include "HiveHelpers/Utils.h"
#include "HiveHelpers/Structs.h"
#include "HiveComponents/AnimatedSprite.h"
#include "HiveScene/GameObject.h"
#include "HiveComponents/TransformComponent.h"




ZenChanController::ZenChanController(Hive::TransformComponent* controller)
	:m_pTarget {controller}
{

}

void ZenChanController::Start()
{
	ControllerComponent::Start();

	m_WalkSpeed = 1500;

	Hive::AnimationData* moveState{ new Hive::AnimationData() };
	moveState->startFrame = 0;
	moveState->endFrame = 3;
	moveState->frameTime = 0.1f;

	Hive::AnimationData* bubbleState{ new Hive::AnimationData() };
	bubbleState->startFrame = 4;
	bubbleState->endFrame = 7;
	bubbleState->frameTime = 0.1f;

	Hive::AnimationData* deathState{ new Hive::AnimationData() };
	deathState->startFrame = 8;
	deathState->endFrame = 11;
	deathState->frameTime = 0.1f;

	m_pAnimatedSprite->AddAnimation(moveState);
	m_pAnimatedSprite->AddAnimation(bubbleState);
	m_pAnimatedSprite->AddAnimation(deathState);

	m_pAnimatedSprite->SetAnimation(0);

	m_pAnimatedSprite->Play();

	m_pRigidbody->GetBody()->SetLinearDamping(0.3f);

}

void ZenChanController::Update()
{
	ControllerComponent::Update();

	glm::vec2 input{};

	float elapsedTime = Hive::Time::GetInstance().GetElapsedTime();


	if (input.x < 0) m_pAnimatedSprite->SetFlip(true);
	if (input.x > 0) m_pAnimatedSprite->SetFlip(false);

	switch (m_State)
	{
	case moving:
		if (m_pTarget->GetPosition().x < gameObject->GetTransform()->GetPosition().x) input.x = -1.f;
		if (m_pTarget->GetPosition().x > gameObject->GetTransform()->GetPosition().x) input.x = 1.f;

		m_Velocity.x = input.x * m_WalkSpeed * elapsedTime;
		m_Velocity.y = input.y * m_JumpSpeed * elapsedTime;

		m_pAnimatedSprite->SetAnimation(0);
		break;
	case bubble:
		m_Velocity.y = -m_JumpSpeed * elapsedTime;
		m_pAnimatedSprite->SetAnimation(1);
		break;
	case dead:
		m_pAnimatedSprite->SetAnimation(2);
		break;
	default:
		break;
	}


}

void ZenChanController::FixedUpdate()
{
	ControllerComponent::FixedUpdate();

	b2Body* body = m_pRigidbody->GetBody();

	b2Vec2 vel = body->GetLinearVelocity();

	glm::vec2 velocityPixelSpace = Hive::ToPixelSpace(vel);

	glm::vec2 velocityChange = m_Velocity - velocityPixelSpace;
	velocityChange *= body->GetMass();

	body->ApplyLinearImpulseToCenter({ Hive::ToPhysicsSpace(velocityChange.x) ,0.f }, true);
	body->ApplyLinearImpulseToCenter({ 0 , Hive::ToPhysicsSpace(m_Velocity.y) }, true);

}

void ZenChanController::OnCollisionEnter2D(const Hive::Collision& collision)
{
	
	if (collision.objHit->GetTag() == "Player" && m_State == moving) 
	{
		SetState(bubble);
		return;
	}
	if (collision.objHit->GetTag() == "Player" && m_State == bubble)
	{
		SetState(dead);
		return;
	}
}
