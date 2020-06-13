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
		RigidBodySettings(b2BodyType bodyType, bool isBullet = false, bool fixedRotation = false, float gravityMultiplier = 1.f)
			: m_BodyType{ bodyType }
			, m_IsBullet{ isBullet }
			, m_FixedRotation{ fixedRotation }
			, m_GravityMultiplier{ gravityMultiplier }
		{}

		b2BodyType m_BodyType;
		bool m_IsBullet;
		bool m_FixedRotation;
		float m_GravityMultiplier;

	};


	struct PhysicsSettings
	{
		PhysicsSettings(uint32 posIts = 6, uint32 velIts = 8, float fixedTimeStep = 1.f/60.f)
			:positionIterations{posIts}
			,velocityIterations {velIts}
			,fixedStep {fixedTimeStep}
		{}

		uint32 positionIterations;
		uint32 velocityIterations;
		float fixedStep;
	};
}



