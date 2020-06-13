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
	const glm::vec2 position = gameObject->GetTransform()->GetPosition();
	const float rotation = gameObject->GetTransform()->GetRotation();
	const glm::vec2 scale = gameObject->GetTransform()->GetScale();
	
	
	Renderer::GetInstance().RenderTexture(m_pTexture, position,scale, rotation);
}
