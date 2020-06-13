#include "HivePCH.h"
#include "Texture2D.h"



Hive::Texture2D::Texture2D(SDL_Texture* texture)
	:m_Height{}
	,m_Width{}
{
	m_Texture = texture;

	int width{};
	int height{};

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	m_Width = width;
	m_Height = height;
}


Hive::Texture2D::~Texture2D()
{
	if(m_Texture)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}


	
}

void Hive::Texture2D::SetSDLTexture(SDL_Texture* texture)
{
	m_Texture = texture;

	int width{};
	int height{};

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	m_Width = width;
	m_Height = height;
}

SDL_Texture* Hive::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

