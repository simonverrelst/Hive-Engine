#pragma once
#include "HivePhysics/Physics.h"

#pragma warning( push )
#pragma warning( disable : 4201)
#include "glm/vec2.hpp"
#pragma warning( pop ) 


#include "Box2D/Box2D.h"


namespace Hive
{
	inline glm::vec2 ToVector2D(const b2Vec2& vec)
	{
		return glm::vec2{ vec.x,vec.y };
	}

	inline b2Vec2 ToBox2D(const glm::vec2 & vec)
	{
		return b2Vec2{ vec.x,vec.y };
	}

	inline glm::vec2 ToPixelSpace(const b2Vec2& vec)
	{
		float ppm = Physics::GetInstance().GetPixelPerMeter();
		return glm::vec2{ vec.x * ppm,vec.y * ppm };
	}

	inline b2Vec2 ToPhysicsSpace(const glm::vec2& vec)
	{
		float ppm = Physics::GetInstance().GetPixelPerMeter();
		return b2Vec2{ vec.x / ppm,vec.y / ppm };
	}


}

