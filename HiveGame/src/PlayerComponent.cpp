#include "PlayerComponent.h"
#include "HiveInput/PlayerInput.h"
#include "HiveHelpers/Time.h"
#include "HiveHelpers/Utils.h"


PlayerComponent::PlayerComponent(Hive::PlayerController* controller)
	: m_pController{ controller }
{

}


void PlayerComponent::Start()
{
	ControllerComponent::Start();
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
	m_Velocity.y = input.y * m_WalkSpeed * elapsedTime;
}

void PlayerComponent::FixedUpdate()
{
	ControllerComponent::FixedUpdate();

	m_pRigidbody->GetBody()->ApplyLinearImpulseToCenter(Hive::ToVectorBox2D(Hive::ToPhysicsSpace(m_Velocity)),true);
}
