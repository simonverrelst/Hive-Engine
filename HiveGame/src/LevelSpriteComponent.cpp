#include "LevelSpriteComponent.h"
#include "HiveHelpers/ResourceManager.h"
#include "HiveRender/Renderer.h"
#include "HiveScene/GameObject.h"
#include "HiveComponents/TransformComponent.h"
#include "HiveRender/Texture2D.h"


Hive::Texture2D* LevelSpriteComponent::m_pTexture = nullptr;

int LevelSpriteComponent::m_CurrentLevelIndex{};


LevelSpriteComponent::LevelSpriteComponent(const std::string& filePath)
	: m_AnimationData{}
{

	if(!m_pTexture)
		m_pTexture = Hive::ResourceManager::GetInstance().LoadTexture(filePath);

	m_AnimationData.texture = m_pTexture;
	m_AnimationData.frameNrCollums = 10;
	m_AnimationData.frameNrRows = 10;
	m_AnimationData.frameWidth = int(m_pTexture->GetWidth() / m_AnimationData.frameNrCollums);
	m_AnimationData.frameHeight = int(m_pTexture->GetHeight() / m_AnimationData.frameNrRows);
	m_AnimationData.currentFrameNumber = m_CurrentLevelIndex;

}


LevelSpriteComponent::~LevelSpriteComponent()
{
	if (m_pTexture) 
	{ 
		delete m_pTexture;
		m_pTexture = nullptr;
	}
}

void LevelSpriteComponent::Render()
{
	glm::vec2 position = gameObject->GetTransform()->GetPosition();
	position -= glm::vec2{ m_AnimationData.frameWidth /2,m_AnimationData.frameHeight /2 };
	const float rotation = gameObject->GetTransform()->GetRotation();
	const glm::vec2 scale = gameObject->GetTransform()->GetScale();

	Hive::Renderer::GetInstance().RenderTexture(m_AnimationData, position, scale, rotation,false);
}

void LevelSpriteComponent::Update()
{
	m_AnimationData.currentFrameNumber = m_CurrentLevelIndex;
}
