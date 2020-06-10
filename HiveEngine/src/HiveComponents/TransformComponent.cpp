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

	void TransformComponent::SetPosition(float x, float y, float z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
	}
}


