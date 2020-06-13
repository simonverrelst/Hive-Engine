#include "HivePCH.h"

#include "SpriteComponent.h"

#include "HiveHelpers/ResourceManager.h"
#include "HiveRender/Renderer.h"
#include "HiveScene/GameObject.h"
#include "HiveComponents/TransformComponent.h"

Hive::SpriteComponent::SpriteComponent(const std::string& filePath)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filePath);
}

Hive::SpriteComponent::~SpriteComponent()
{
	SafeDelete(m_pTexture);
}

void Hive::SpriteComponent::Start()
{

}

void Hive::SpriteComponent::Update()
{
}

void Hive::SpriteComponent::Render()
{
	const auto position = gameObject->GetTransform()->GetPosition();
	
	
	Renderer::GetInstance().RenderTexture(m_pTexture, position.x, position.y);
}
