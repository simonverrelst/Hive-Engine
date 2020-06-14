#pragma once
#include "HiveComponents/Component.h"
#include "HiveHelpers/Utils.h"
#include <vector>

namespace Hive
{
	class AnimatedSprite : public Component
	{
	public:
		AnimatedSprite(const std::string & filePath);
		virtual ~AnimatedSprite();

		void Start() override;
		void Update() override;
		void Render() override;

		void SetAnimation(size_t index);
		void AddAnimation(AnimationData* animData) { m_Animations.push_back(animData); }
		void Play() { m_IsPlaying = true; }
		void Stop() { m_IsPlaying = false; }

	protected:
		std::vector<AnimationData*> m_Animations;
		AnimationData* m_pCurrentAnim;

		Texture2D * m_pSpriteSheet;
	private:
		bool m_IsPlaying = false;
	};
}



