#pragma once
#include "HiveHelpers/Singleton.h"

struct SDL_Window;
struct SDL_Renderer;

#pragma warning( push )
#pragma warning( disable : 4201)
#include "glm/vec2.hpp"
#pragma warning( pop ) 

namespace Hive
{
	class Texture2D;

	class Renderer final : public Singleton<Renderer>
	{
	public:
		void Init(SDL_Window * window);
		void Destroy();

		void RenderStart() const;

		void RenderEnd() const;

		void RenderTexture(Texture2D * texture, const glm::vec2 & pos, const glm::vec2 & scale, float rotation) const;
		void RenderTexture(const AnimationData& animData, const glm::vec2& pos, const glm::vec2& scale, float rotation) const;

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }

	public:

		void DrawPoint(const b2Vec2& p, float size, const b2Color& color);
		void DrawTransform(const b2Transform& xf);
		void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
		void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color);
		void DrawCircle(const b2Vec2& center, float radius, const b2Color& color);
		void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
		void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

	private:
		friend class Singleton<Renderer>;
		SDL_Renderer* m_Renderer{};
	};
}




