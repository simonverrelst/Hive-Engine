#include "HivePCH.h"
#include "AnimatedSprite.h"
#include "HiveHelpers/Time.h"
#include "HiveScene/GameObject.h"
#include "TransformComponent.h"
#include "HiveRender/Renderer.h"
#include "HiveHelpers/ResourceManager.h"

Hive::AnimatedSprite::AnimatedSprite(const std::string& filePath)
	: m_pCurrentAnim{}
	, m_IsPlaying {true}
{
	if (!m_pSpriteSheet)
		m_pSpriteSheet = Hive::ResourceManager::GetInstance().LoadTexture(filePath);
}

Hive::AnimatedSprite::~AnimatedSprite()
{
	SafeDelete(m_pSpriteSheet);

	for (auto& anim : m_Animations) 
	{
		SafeDelete(anim);
	}
}

void Hive::AnimatedSprite::Start()
{
	m_AnimationData.texture = m_pTexture;
	m_AnimationData.frameNrCollums = 10;
	m_AnimationData.frameNrRows = 10;
	m_AnimationData.frameWidth = int(m_pTexture->GetWidth() / m_AnimationData.frameNrCollums);
	m_AnimationData.frameHeight = int(m_pTexture->GetHeight() / m_AnimationData.frameNrRows);

	throw std::logic_error("The method or operation is not implemented.");
}

void Hive::AnimatedSprite::Update()
{
	if (!m_IsPlaying) return;

	float elapsedSec = Time::GetInstance().GetElapsedTime();

	m_pCurrentAnim->accumelatedSec += elapsedSec;
	if (m_pCurrentAnim->accumelatedSec >= m_pCurrentAnim->frameTime)
	{
		++m_pCurrentAnim->currentFrameNumber;
		if (m_pCurrentAnim->currentFrameNumber > m_pCurrentAnim->endFrame)
		{
			m_pCurrentAnim->currentFrameNumber = m_pCurrentAnim->startFrame;
		}
		m_pCurrentAnim->accumelatedSec -= m_pCurrentAnim->frameTime;
	}
}

void Hive::AnimatedSprite::Render()
{
	TransformComponent* transComp = gameObject->GetTransform();

	glm::vec2 position = transComp->GetPosition();
	position -= glm::vec2{ m_pCurrentAnim->frameWidth,m_pCurrentAnim->frameHeight };
	const float rotation = transComp->GetRotation();
	const glm::vec2 scale = transComp->GetScale();

	Hive::Renderer::GetInstance().RenderTexture(*m_pCurrentAnim, position, scale, rotation);
}

void Hive::AnimatedSprite::SetAnimation(size_t index)
{
	if (index > m_Animations.size()) return;
	m_pCurrentAnim = m_Animations[index];
}
