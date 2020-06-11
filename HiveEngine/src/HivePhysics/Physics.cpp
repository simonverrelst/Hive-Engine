#include "HivePCH.h"
#include "Physics.h"
#include "PhysicsContactListener.h"



void Hive::Physics::Start()
{
	m_pWorld = new b2World(b2Vec2{ 0,-9.81f });
	m_pWorld->SetAllowSleeping(true);
	m_pWorld->SetContinuousPhysics(true);
	m_pWorld->SetContactListener(new PhysicsContactListener());

}

void Hive::Physics::Destroy()
{
	
	ClearBodies();
	
	delete m_pWorld;

}

void Hive::Physics::Step()
{
	m_pWorld->Step(1 / 60.f, m_AmountOfPositionIts, m_AmountOfVelocityIts);
}

void Hive::Physics::ClearBodies()
{
	auto currentBody = m_pWorld->GetBodyList();

	// Clearing all bodies from the world
	while (currentBody)
	{
		b2Body* nextBody = currentBody->GetNext();
		m_pWorld->DestroyBody(currentBody);
		currentBody = nextBody;
	}
}

