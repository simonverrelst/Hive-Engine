#pragma once
#include "ControllerComponent.h"
#include "ActionMappings.h"



namespace Hive
{
	class PlayerController;
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
};

