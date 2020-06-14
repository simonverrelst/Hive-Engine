#include "HivePCH.h"
#include "Physics.h"
#include "PhysicsContactListener.h"
#include "HiveHelpers/Time.h"
#include "HiveRender/Renderer.h"
#include "HiveHelpers/Logger.h"



void Hive::Physics::Init(const PhysicsSettings & settings)
{
	m_Settings = settings;

	m_pContactListener = new PhysicsContactListener();
	m_pPhysicsDebugger = new PhysicsDebugger();

	m_pWorld = new b2World(b2Vec2{ 0,9.81f });
	m_pWorld->SetAllowSleeping(true);
	m_pWorld->SetContinuousPhysics(true);
	m_pWorld->SetContactListener(m_pContactListener);
	m_pWorld->GetGravity();
	m_pWorld->SetWarmStarting(true);
	m_pWorld->SetSubStepping(true);
	m_pWorld->SetDebugDraw(m_pPhysicsDebugger);

	uint32 flags{};
	flags += b2Draw::e_shapeBit;
	//flags += b2Draw::e_aabbBit;
	//flags += b2Draw::e_centerOfMassBit;

	m_pPhysicsDebugger->SetFlags(flags);

}

void Hive::Physics::Destroy()
{
	
	ClearBodies();
	
	SafeDelete(m_pContactListener);

	SafeDelete(m_pPhysicsDebugger);

	SafeDelete(m_pWorld);

}

void Hive::Physics::Step()
{
	//LOG_ENGINE_TRACE("Physics trace: elapsedSec: {0} , fixedStep: {1}",Time::GetInstance().GetElapsedTime() ,  m_Settings.fixedStep );
	m_pWorld->Step(m_Settings.fixedStep, m_Settings.velocityIterations, m_Settings.positionIterations);
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

void Hive::Physics::DebugRender()
{
	if(m_pWorld)
		m_pWorld->DebugDraw();
}

void Hive::PhysicsDebugger::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	Renderer::GetInstance().DrawPolygon(vertices, vertexCount, color);
}

void Hive::PhysicsDebugger::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	Renderer::GetInstance().DrawSolidPolygon(vertices, vertexCount, color);
}

void Hive::PhysicsDebugger::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
	Renderer::GetInstance().DrawCircle(center, radius, color);
}

void Hive::PhysicsDebugger::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
	Renderer::GetInstance().DrawSolidCircle(center, radius, axis, color);
}

void Hive::PhysicsDebugger::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	Renderer::GetInstance().DrawSegment(p1, p2, color);
}

void Hive::PhysicsDebugger::DrawTransform(const b2Transform& xf)
{
	Renderer::GetInstance().DrawTransform(xf);
}

void Hive::PhysicsDebugger::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	Renderer::GetInstance().DrawPoint(p, size, color);
}
