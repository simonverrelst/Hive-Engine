#include "HivePCH.h"
#include "AnimatedSprite.h"
#include "HiveHelpers/Time.h"
#include "HiveScene/GameObject.h"
#include "TransformComponent.h"
#include "HiveRender/Renderer.h"
#include "HiveHelpers/ResourceManager.h"
#include "HiveRender/Texture2D.h"

Hive::AnimatedSprite::AnimatedSprite(const std::string& filePath,int sheetNrCols, int sheetNrRows)
	: m_pCurrentAnim{}
	, m_IsPlaying {true}
	, m_AmountOfCols { sheetNrCols}
	,m_AmountOfRows { sheetNrRows}
	,m_RenderFlipped{false}
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


}

void Hive::AnimatedSprite::Update()
{
	if (!m_IsPlaying && !m_pCurrentAnim) return;

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
	
	const float rotation = transComp->GetRotation();
	const glm::vec2 scale = transComp->GetScale();

	position -= glm::vec2{ (m_pCurrentAnim->frameWidth / 2.f)* scale.x ,(m_pCurrentAnim->frameHeight / 2.f)* scale.y };


	Hive::Renderer::GetInstance().RenderTexture(*m_pCurrentAnim, position, scale, rotation,m_RenderFlipped);
}

void Hive::AnimatedSprite::SetAnimation(size_t index)
{
	if (index > m_Animations.size()) return;
	m_pCurrentAnim = m_Animations[index];
}

void Hive::AnimatedSprite::AddAnimation(AnimationData* animData)
{
	m_Animations.push_back(animData);

	animData->texture = m_pSpriteSheet;
	animData->frameNrRows = m_AmountOfRows;
	animData->frameNrCollums = m_AmountOfCols;
	animData->frameWidth = int(m_pSpriteSheet->GetWidth() / animData->frameNrCollums);
	animData->frameHeight = int(m_pSpriteSheet->GetHeight() / animData->frameNrRows);
}
