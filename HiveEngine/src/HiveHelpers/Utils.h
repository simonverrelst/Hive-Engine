#pragma once
#include "HivePhysics/Physics.h"

#pragma warning( push )
#pragma warning( disable : 4201)
#include "glm/vec2.hpp"
#pragma warning( pop ) 

#include "glm/trigonometric.hpp"

#include "Box2D/Box2D.h"


namespace Hive
{
	inline glm::vec2 ToVector2D(const b2Vec2& vec)
	{
		return glm::vec2{ vec.x,vec.y };
	}

	inline b2Vec2 ToVectorBox2D(const glm::vec2 & vec)
	{
		return b2Vec2{ vec.x,vec.y };
	}

	inline glm::vec2 ToPixelSpace(const b2Vec2& vec)
	{
		float ppm = Physics::GetInstance().GetPixelPerMeter();
		return glm::vec2{ vec.x * ppm,vec.y * ppm };
	}

	inline glm::vec2 ToPhysicsSpace(const glm::vec2& vec)
	{
		float ppm = Physics::GetInstance().GetPixelPerMeter();
		return glm::vec2{ vec.x / ppm,vec.y / ppm };
	}

	inline float ToPhysicsSpace(float value) 
	{
		float ppm = Physics::GetInstance().GetPixelPerMeter();
		return value /= ppm;
	}

	inline float ToRadians( float angle)
	{
		return glm::radians(angle);
	}

	inline float ToEuler(float angle)
	{
		return glm::degrees(angle);
	}
}

