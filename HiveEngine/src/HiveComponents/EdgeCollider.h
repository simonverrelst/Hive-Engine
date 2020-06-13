#pragma once
#include "ColliderComponent.h"

namespace Hive
{
	class EdgeCollider final : public ColliderComponent
	{
	public:
		EdgeCollider(const ColliderSettings& settings, const glm::vec2& offset = {}, float radius = { 10 });
		virtual ~EdgeCollider() = default;

		void Start() override;
	protected:
	private:
		glm::vec2 m_LocalPos;
		float m_Radius;
	};
}