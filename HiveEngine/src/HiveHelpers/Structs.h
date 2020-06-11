#pragma once
#include "Box2D/Box2D.h"



namespace Hive
{
	class GameObject;

	struct Collision
	{
		Hive::GameObject* objHit; // Object that was hit
		b2Contact* contact; // some extra info about the collision and collider
	};

	struct RigidBodySettings
	{
		b2BodyType bodyType;
		bool isBullet{};
		bool fixedRotation{};
		float gravityMultiplier{};

	};
}



