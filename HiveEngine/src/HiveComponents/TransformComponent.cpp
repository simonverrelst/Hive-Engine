#include "HivePCH.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"

namespace Hive
{

	TransformComponent::~TransformComponent()
	{
	}

	void TransformComponent::SetPosition(float x, float y)
	{


		RigidBodyComponent* pRb = gameObject->GetComponent<RigidBodyComponent>();
		if (pRb && !pRb->IsInFixedUpdate())
		{
			pRb->Translate(m_Position);
		}

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


