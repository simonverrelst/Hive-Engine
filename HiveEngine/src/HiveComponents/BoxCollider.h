#pragma once
#include "ColliderComponent.h"


namespace Hive
{
	class BoxCollider final : public ColliderComponent
	{
	public:
		BoxCollider(const ColliderSettings& settings,const glm::vec2& boxPos = {}, const glm::vec2& boxSize = {30,30});
		virtual ~BoxCollider() = default;

		void Start() override;

	protected:

	
	private:

		glm::vec2 m_BoxPos;
		glm::vec2 m_BoxSize;
	};

}