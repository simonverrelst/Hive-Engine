#pragma once
#include "ControllerComponent.h"
#include "ActionMappings.h"

namespace Hive
{
	class TransformComponent;
	class AnimatedSprite;
}

enum ZenChanState
{
	moving,
	bubble,
	dead
};

class ZenChanController final : public ControllerComponent
{
public:

	ZenChanController(Hive::TransformComponent* controller);
	virtual ~ZenChanController() = default;



protected:
	void Start() override;

	void Update() override;

	void FixedUpdate() override;

	void SetState(ZenChanState state) { m_State = state; }

	void OnCollisionEnter2D(const Hive::Collision& collision) override;

private:

	Hive::TransformComponent * m_pTarget;

	float m_WalkSpeed = 10000.f;
	float m_JumpSpeed = 1000.f;

	ZenChanState m_State;
};

