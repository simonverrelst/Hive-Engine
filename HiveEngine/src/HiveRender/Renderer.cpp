#include "HivePCH.h"
#include "HiveScene/SceneManager.h"
#include "Renderer.h"
#include "Texture2D.h"
#include "Box2D/Box2D.h"
#include "HiveHelpers/Utils.h"


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

void Hive::Renderer::RenderTexture(Texture2D * texture, const float x, const float y, const float width, const float height) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	dst.w = static_cast<int>(width);
	dst.h = static_cast<int>(height);
	SDL_RenderCopy(Renderer::GetInstance().GetSDLRenderer(), texture->GetSDLTexture(), nullptr, &dst);
	
}

void Hive::Renderer::RenderTexture(Texture2D * texture, float x, float y) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	SDL_QueryTexture(texture->GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(Renderer::GetInstance().GetSDLRenderer(), texture->GetSDLTexture(), nullptr, &dst);
}


void Hive::Renderer::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{

	UNREFERENCED_PARAMETER(vertices);
	UNREFERENCED_PARAMETER(vertexCount);
	UNREFERENCED_PARAMETER(color);
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
	SDL_Renderer* renderer = GetSDLRenderer();

	glm::vec2 point1 = ToPixelSpace(p1);
	glm::vec2 point2 = ToPixelSpace(p2);

	SDL_SetRenderDrawColor(renderer, uint8(color.r * 255.f), uint8(color.b * 255.f), uint8(color.g * 255.f), uint8(color.a * 255.f));
	SDL_RenderDrawLine(renderer, int(point1.x), int(point1.y), int(point2.x), int(point2.y));
}

void Hive::Renderer::DrawTransform(const b2Transform& xf)
{
	SDL_Renderer* renderer = GetSDLRenderer();

	glm::vec2 origin = ToPixelSpace(xf.p);
	glm::vec2 xAxis = ToPixelSpace({ xf.p.x + xf.q.GetXAxis().y,xf.p.y + xf.q.GetXAxis().y });
	glm::vec2 yAxis = ToPixelSpace({ xf.p.x + xf.q.GetYAxis().y,xf.p.y + xf.q.GetYAxis().y });

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, int(origin.x), int(origin.y), int(xAxis.x), int(xAxis.y));
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, int(origin.x), int(origin.y), int(yAxis.x), int(yAxis.y));
}

void Hive::Renderer::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	UNREFERENCED_PARAMETER(size);

	SDL_Renderer* renderer = GetSDLRenderer();

	glm::vec2 point = ToPixelSpace(p);

	SDL_SetRenderDrawColor(renderer, uint8(color.r * 255.f), uint8(color.b * 255.f), uint8(color.g * 255.f), uint8(color.a * 255.f));
	SDL_RenderDrawPoint(renderer, int(point.x), int(point.y));
}