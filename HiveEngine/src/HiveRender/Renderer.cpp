#include "HivePCH.h"
#include "HiveScene/SceneManager.h"
#include "Renderer.h"

#include "Texture2D.h"


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
