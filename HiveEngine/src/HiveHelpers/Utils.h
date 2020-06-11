#pragma once
#include "glm/vec2.hpp"
#include "Box2D/Box2D.h"

namespace Hive
{
	inline glm::vec2 ToVector2(const b2Vec2& vec)
	{
		return glm::vec2{ vec.x,vec.y };
	}

	inline b2Vec2 ToBox2dVector2(const glm::vec2 & vec)
	{
		return b2Vec2{ vec.x,vec.y };
	}


}

