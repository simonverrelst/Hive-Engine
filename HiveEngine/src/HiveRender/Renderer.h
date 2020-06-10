#pragma once
#include "HiveHelpers/Singleton.h"

struct SDL_Window;
struct SDL_Renderer;

class Texture2D;

namespace Hive
{
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void Init(SDL_Window * window);
		void Render() const;
		void Destroy();

		void RenderTexture(Texture2D * texture, float x, float y) const;
		void RenderTexture(Texture2D * texture, float x, float y, float width, float height) const;

		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }
	private:
		friend class Singleton<Renderer>;
		SDL_Renderer* m_Renderer{};
	};
}




