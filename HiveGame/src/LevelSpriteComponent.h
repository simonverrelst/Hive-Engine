#pragma once
#include "HiveComponents/Component.h"
#include <string>
#include <vector>
#include "HiveHelpers/Structs.h"

namespace Hive
{
	class Texture2D;
}


class LevelSpriteComponent final : public Hive::Component
{
public:
	LevelSpriteComponent(const std::string& filePath);
	virtual ~LevelSpriteComponent();

	static void SetLevelIndex(int index) { m_CurrentLevelIndex = index; };

	

protected:
	void Render() override;

	void Update() override;


	static int m_CurrentLevelIndex;

private:
	static Hive::Texture2D* m_pTexture;
	Hive::AnimationData m_AnimationData;
};

