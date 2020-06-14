#pragma once
#include "ControllerComponent.h"
#include "ActionMappings.h"


//enum PlayerAnimations
//{
//	walk,
//	jump,
//	eat
//};

namespace Hive
{
	class PlayerController;
	class AnimatedSprite;
}

class PlayerComponent final : public ControllerComponent
{
public:

	PlayerComponent(Hive::PlayerController* controller);
	virtual ~PlayerComponent() = default;

protected:
	void Start() override;

	void Update() override;

	void FixedUpdate() override;
private:
	
	Hive::PlayerController * m_pController;

	float m_WalkSpeed = 1500.f;
	float m_JumpSpeed = 1000.f;
};

