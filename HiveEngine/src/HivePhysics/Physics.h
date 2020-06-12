#pragma once
#include "HiveHelpers/Singleton.h"
#include "HiveScene/GameObject.h"
#include "HiveHelpers/Structs.h"

#include <Box2D/Box2D.h>

namespace Hive
{
	class PhysicsDebugger final : public b2Draw 
	{
	
		void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;

		void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;

		void DrawCircle(const b2Vec2& center, float radius, const b2Color& color) override;

		void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) override;

		void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;

		void DrawTransform(const b2Transform& xf) override;

		void DrawPoint(const b2Vec2& p, float size, const b2Color& color) override;

	};


	class Physics final : public Singleton<Physics>
	{
	public:
		void Init(const PhysicsSettings & settings);
		void Destroy();

		void Step();

		void SetGravity(const b2Vec2& vec) { if (m_pWorld) m_pWorld->SetGravity(vec); };

		b2Vec2 GetGravity() const { if (m_pWorld) m_pWorld->GetGravity(); };

		b2World* GetPhysicsWorld() { return m_pWorld; };

		float GetPixelPerMeter() const { return m_PixelsPerMeter; };

		float GetFixedTimeStep() const { return m_Settings.fixedStep; };

		void DebugRender();
	private:

		void ClearBodies();

	private:
		b2World* m_pWorld{};

		PhysicsSettings m_Settings{};


		float m_PixelsPerMeter{ 100.f };
	};


}



