#pragma once
#include "HiveHelpers/Singleton.h"
#include "HiveScene/GameObject.h"

#include <Box2D/Box2D.h>

namespace Hive
{

	class Physics final : public Singleton<Physics>
	{
	public:
		void Start();
		void Destroy();

		void Step();

		void SetPositionIts(const int amountOfIterations) { m_AmountOfPositionIts = amountOfIterations; };
		void SetVelocityIts(const int amountOfIterations) { m_AmountOfVelocityIts = amountOfIterations; };

		void SetGravity(const b2Vec2& vec) { if (m_pWorld) m_pWorld->SetGravity(vec); };

		b2Vec2 GetGravity() const { if (m_pWorld) m_pWorld->GetGravity(); };

		b2World* GetPhysicsWorld() { return m_pWorld; };
	private:

		void ClearBodies();

	private:
		b2World* m_pWorld{};

		int m_AmountOfPositionIts{2};
		int m_AmountOfVelocityIts{6};
	};


}



