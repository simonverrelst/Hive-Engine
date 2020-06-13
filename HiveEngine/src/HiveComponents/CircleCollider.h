#pragma once
#include "ColliderComponent.h"
namespace Hive
{
	class CircleCollider final : public ColliderComponent
	{
	public:
		CircleCollider(const ColliderSettings& settings, const glm::vec2& offset = {}, float radius = {10});
		virtual ~CircleCollider() = default;

		void Start() override;
	protected:
	private:
		glm::vec2 m_LocalPos;
		float m_Radius;
	};

}