#pragma once
#include "HiveComponents/Component.h"
#include "HiveRender/Texture2D.h"

namespace Hive
{
	class TransformComponent;
	class SpriteComponent :
		public Component
	{
	public:
		SpriteComponent(const std::string& filePath);
		virtual ~SpriteComponent();

		// Inherited via Component
		virtual void Start() override;
		virtual void Update() override;
		virtual void Render() override;
	private:
		Texture2D * texture;
	};

}