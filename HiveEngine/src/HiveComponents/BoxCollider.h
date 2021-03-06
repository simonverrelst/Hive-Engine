#pragma once
#include "ColliderComponent.h"


namespace Hive
{
	class BoxCollider final : public ColliderComponent
	{
	public:
		BoxCollider(const ColliderSettings& settings,const glm::vec2& offset = {}, const glm::vec2& boxSize = {10,10});
		virtual ~BoxCollider() = default;

		void Start() override;

	protected:

	
	private:

		glm::vec2 m_BoxPos;
		glm::vec2 m_BoxSize;
	};

}