#include "HivePCH.h"
#include "HiveScene/SceneManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "Box2D/Box2D.h"




void Hive::Renderer::Init(SDL_Window* window)
{
	m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
	SDL_SetRenderDrawColor(m_Renderer, 50, 50, 50, 255);
}

void Hive::Renderer::Render() const
{
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 1);

	SceneManager::GetInstance().Render();

	SDL_RenderPresent(m_Renderer);
}

void Hive::Renderer::Destroy()
{
	if (m_Renderer != nullptr)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void Hive::Renderer::RenderTexture(Texture2D* texture, const glm::vec2& pos, const glm::vec2& scale, float rotation) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(pos.x);
	dst.y = static_cast<int>(pos.y);
	dst.w = static_cast<int>(texture->GetWidth() * scale.x);
	dst.h = static_cast<int>(texture->GetHeight() * scale.y);

	SDL_RenderCopyEx(m_Renderer, texture->GetSDLTexture(), nullptr, &dst,ToEuler(rotation),nullptr,SDL_RendererFlip::SDL_FLIP_NONE);

}

void Hive::Renderer::RenderTexture(const AnimationData &animData, const glm::vec2& pos, const glm::vec2& scale, float rotation) const
{
	SDL_Rect src;
	src.x = static_cast<int>((animData.frameNumber % animData.frameNrCollums) * animData.frameWidth * scale.x);
	src.y = static_cast<int>((animData.frameNumber / animData.frameNrRows) * animData.frameHeight * scale.y);
	src.w = animData.frameWidth;
	src.h = animData.frameWidth;

	SDL_Rect dst;
	dst.x = static_cast<int>(pos.x);
	dst.y = static_cast<int>(pos.y);
	dst.w = static_cast<int>(animData.texture->GetWidth() * scale.x);
	dst.h = static_cast<int>(animData.texture->GetHeight() * scale.y);

	SDL_Point center{};
	center.x = static_cast<int>((animData.frameWidth * scale.x) / 2.f);
	center.y = static_cast<int>((animData.frameHeight * scale.y )/ 2.f);
		

	SDL_RenderCopyEx(m_Renderer, animData.texture->GetSDLTexture(), &src, &dst, ToEuler(rotation), &center, SDL_RendererFlip::SDL_FLIP_NONE);

}

void Hive::Renderer::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, uint8(color.r * 255), uint8(color.b * 255), uint8(color.g * 255), uint8(color.a * 255));
	
	std::vector<SDL_Point> points{};
	points.resize(vertexCount);

	for (int i = 0; i < vertexCount; i++)
	{
		glm::vec2 pos = ToPixelSpace(vertices[i]);
		points[i].x  = int(pos.x);
		points[i].y = int(pos.y);
	}

	SDL_RenderDrawLines(m_Renderer, points.data(), vertexCount);

}

void Hive::Renderer::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	UNREFERENCED_PARAMETER(vertices);
	UNREFERENCED_PARAMETER(vertexCount);
	UNREFERENCED_PARAMETER(color);
}

void Hive::Renderer::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
	UNREFERENCED_PARAMETER(center);
	UNREFERENCED_PARAMETER(radius);
	UNREFERENCED_PARAMETER(color);
}

void Hive::Renderer::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
	UNREFERENCED_PARAMETER(center);
	UNREFERENCED_PARAMETER(radius);
	UNREFERENCED_PARAMETER(axis);
	UNREFERENCED_PARAMETER(color);
}

void Hive::Renderer::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	glm::vec2 point1 = ToPixelSpace(p1);
	glm::vec2 point2 = ToPixelSpace(p2);

	SDL_SetRenderDrawColor(m_Renderer, uint8(color.r * 255.f), uint8(color.b * 255.f), uint8(color.g * 255.f), uint8(color.a * 255.f));
	SDL_RenderDrawLine(m_Renderer, int(point1.x), int(point1.y), int(point2.x), int(point2.y));
}

void Hive::Renderer::DrawTransform(const b2Transform& xf)
{
	

	glm::vec2 origin = ToPixelSpace(xf.p);
	glm::vec2 xAxis = ToPixelSpace({ xf.p.x + xf.q.GetXAxis().y,xf.p.y + xf.q.GetXAxis().y });
	glm::vec2 yAxis = ToPixelSpace({ xf.p.x + xf.q.GetYAxis().y,xf.p.y + xf.q.GetYAxis().y });

	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(m_Renderer, int(origin.x), int(origin.y), int(xAxis.x), int(xAxis.y));
	SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(m_Renderer, int(origin.x), int(origin.y), int(yAxis.x), int(yAxis.y));
}

void Hive::Renderer::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	UNREFERENCED_PARAMETER(size);


	glm::vec2 point = ToPixelSpace(p);

	SDL_SetRenderDrawColor(m_Renderer, uint8(color.r * 255.f), uint8(color.b * 255.f), uint8(color.g * 255.f), uint8(color.a * 255.f));
	SDL_RenderDrawPoint(m_Renderer, int(point.x), int(point.y));
}