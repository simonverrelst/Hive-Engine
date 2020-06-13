#pragma once
struct SDL_Texture;

	/**
	 * Simple RAII wrapper for an SDL_Texture
	 */

namespace Hive
{
	class Texture2D
	{
	public:
		SDL_Texture* GetSDLTexture() const;
		explicit Texture2D(SDL_Texture* texture);
		~Texture2D();

		void SetSDLTexture(SDL_Texture* texture);

		Texture2D(const Texture2D&) = delete;
		Texture2D(Texture2D&&) = delete;
		Texture2D& operator= (const Texture2D&) = delete;
		Texture2D& operator= (const Texture2D&&) = delete;


		float GetWidth() { return float(m_Width); }
		float GetHeight() { return float(m_Height); }
		

	private:
		SDL_Texture* m_Texture;

		int m_Width;
		int m_Height;
	};
}



