#pragma once
#include "HiveComponents/Component.h"
#include "HiveHelpers/Utils.h"
#include <vector>
#include <string>

namespace Hive
{
	class AnimatedSprite : public Component
	{
	public:
		AnimatedSprite(const std::string& filePath, int sheetNrCols, int sheetNrRows);
		virtual ~AnimatedSprite();

		void Start() override;
		void Update() override;
		void Render() override;

		void SetAnimation(size_t index);
		void AddAnimation(AnimationData* animData);
		void Play() { m_IsPlaying = true; }
		void Stop() { m_IsPlaying = false; }

		void SetFlip(bool value) { m_RenderFlipped = value; }

	protected:
		std::vector<AnimationData*> m_Animations;
		AnimationData* m_pCurrentAnim;

		Texture2D * m_pSpriteSheet;
		int m_AmountOfCols;
		int m_AmountOfRows;
		bool m_RenderFlipped;
	private:
		bool m_IsPlaying = false;
	};
}



