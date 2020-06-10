#include "HivePCH.h"
#include "Texture2D.h"


Hive::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_Texture = texture;
}


Hive::Texture2D::~Texture2D()
{
	SDL_DestroyTexture(m_Texture);
}

void Hive::Texture2D::SetSDLTexture(SDL_Texture* texture)
{
	m_Texture = texture;
}

SDL_Texture* Hive::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

