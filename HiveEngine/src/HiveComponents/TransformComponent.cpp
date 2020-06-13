#include "HivePCH.h"
#include "TransformComponent.h"

namespace Hive
{

	TransformComponent::~TransformComponent()
	{
	}

	void TransformComponent::Start()
	{
	}

	void TransformComponent::Update()
	{
	}

	void TransformComponent::Render()
	{
	}

	void TransformComponent::SetPosition(float x, float y)
	{
		m_Position.x = x;
		m_Position.y = y;
	}

	void TransformComponent::SetPosition(const glm::vec2& position)
	{
		SetPosition(position.x, position.y);
	}

	void TransformComponent::SetRotation(float angle, bool euler)
	{
		if (euler)
			angle = ToRadians(angle);

		m_Rotation = angle;
	}

}


