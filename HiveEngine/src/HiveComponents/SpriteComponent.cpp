#include "HivePCH.h"

#include "SpriteComponent.h"

#include "HiveHelpers/ResourceManager.h"
#include "HiveRender/Renderer.h"
#include "HiveScene/GameObject.h"
#include "HiveComponents/TransformComponent.h"

Hive::SpriteComponent::SpriteComponent(const std::string& filePath)
{
	texture = ResourceManager::GetInstance().LoadTexture(filePath);
}

Hive::SpriteComponent::~SpriteComponent()
{
}

void Hive::SpriteComponent::Start()
{
}

void Hive::SpriteComponent::Update()
{
}

void Hive::SpriteComponent::Render()
{
	auto position = gameObject->GetTransform()->GetPosition();
	
	
	Renderer::GetInstance().RenderTexture(texture, position.x, position.y);
}
