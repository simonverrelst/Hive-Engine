#pragma once
#include "HiveScene/Scene.h"
#include "HiveComponents/Component.h"

namespace Hive
{
	class Font;
	class Texture2D;
	class TextComponent final : public Component
	{
	public:
		// Inherited via Component
		virtual void Start() override;
		virtual void Update() override;
		virtual void Render() override;

		void SetText(const std::string& text);

		explicit TextComponent(const std::string& text, Font* font);
		virtual ~TextComponent();
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;

	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		Font* m_pFont;
		Texture2D* m_pTexture;

	};
}



