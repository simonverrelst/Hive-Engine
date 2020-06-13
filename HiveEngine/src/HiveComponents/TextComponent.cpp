#include "HivePCH.h"
#include "TextComponent.h"
#include "HiveRender/Renderer.h"
#include "HiveRender/Font.h"
#include "HiveRender/Texture2D.h"
#include "HiveScene/GameObject.h"
#include "TransformComponent.h"

Hive::TextComponent::TextComponent(const std::string& text, Font * font) 
	: m_NeedsUpdate(true), m_Text(text), m_pFont(font), m_pTexture(new Texture2D(nullptr))
{ }


Hive::TextComponent::~TextComponent()
{
	SafeDelete(m_pFont);
	SafeDelete(m_pTexture);
}

void Hive::TextComponent::Start()
{

}

void Hive::TextComponent::Render()
{
	if (m_pTexture != nullptr)
	{
		const glm::vec2 position = gameObject->GetTransform()->GetPosition();
		const float rotation = gameObject->GetTransform()->GetRotation();
		const glm::vec2 scale = gameObject->GetTransform()->GetScale();

		Renderer::GetInstance().RenderTexture(m_pTexture, position, scale, rotation);
	}
}

void Hive::TextComponent::Update()
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_pFont->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr) 
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr) 
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_pTexture->SetSDLTexture(texture);
		m_NeedsUpdate = false;
	}
}

void Hive::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}



