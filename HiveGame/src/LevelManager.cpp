#include "LevelManager.h"
#include "HiveScene/Scene.h"
#include "HiveScene/GameObject.h"
#include "HiveComponents/TransformComponent.h"
#include "HiveComponents/BoxCollider.h"
#include "HiveComponents/RigidBodyComponent.h"
#include "LevelSpriteComponent.h"



LevelManager::LevelManager(const std::string& levelFile, const std::string& enemyFile)
	:m_Enviroment{}
	,m_Levels{}
	,m_Reader{}
	,m_CurrentLevel{}
	,m_LevelFilePath{levelFile}
	,m_EnemyfilePath{enemyFile}
{

}

LevelManager::~LevelManager()
{

}

void LevelManager::Start()
{

	m_Enviroment.resize(m_AmountOfCols * m_AmountOfRows);
	m_Levels.resize(m_AmountOfLevels);

	for (size_t i = 0; i < m_Enviroment.size(); i++)
	{
		Hive::GameObject* object = new Hive::GameObject();
		m_Enviroment[i] = object;

		object->AddComponent(new LevelSpriteComponent("Sprites/Blocks.png"));
		object->AddComponent(new Hive::RigidBodyComponent(Hive::RigidBodySettings(b2_staticBody)));
		object->AddComponent(new Hive::BoxCollider(Hive::ColliderSettings(), {0.f,0.f}, { 0.1f,0.1f }));

	}

	m_Reader.OpenFile(m_LevelFilePath);

	for (int l = 0; l < m_AmountOfLevels; l++)
	{
		for (int c = 0; c < m_AmountOfRows; c++)
		{
			for (int r = 0; r < 4; r++) // one row consists out of 4 bytes
			{
				unsigned char blocks = m_Reader.Read<unsigned char>();

				unsigned char bitChecker{ 0b10000000 };


				for (int i = 0; i < 8; i++) // each bit in a byte represents a block
				{
					unsigned char value = blocks & bitChecker;
					value /= bitChecker;
					m_Levels[l].push_back(value);
					bitChecker = bitChecker >> 1;
				}
			}
		}
	}

	m_Reader.CloseFile();

	m_Reader.OpenFile(m_EnemyfilePath);

	m_Reader.CloseFile();
}

void LevelManager::NextLevel()
{
	
	m_CurrentLevel++;
	if (m_CurrentLevel % m_AmountOfLevels == 0) m_CurrentLevel = 0;

	for (int r = 0; r < m_AmountOfRows; r++)
	{
		for (int c = 0; c < m_AmountOfCols; c++)
		{
			int index = (r * m_AmountOfCols) + c;
			m_Enviroment[index]->SetActive(m_Levels[m_CurrentLevel][index]);
			LevelSpriteComponent::SetLevelIndex(m_CurrentLevel);
		}
	}
}

void LevelManager::AddLevelToScene()
{
	Hive::Scene* scene = gameObject->GetScene();


	for (int r = 0; r < m_AmountOfRows; r++) 
	{
		for (int c = 0; c < m_AmountOfCols; c++)
		{
			int index = (r * m_AmountOfCols) + c;

			scene->Add(m_Enviroment[index]);
			m_Enviroment[index]->SetActive(m_Levels[m_CurrentLevel][index]);
			m_Enviroment[index]->GetTransform()->SetPosition(glm::vec2{ c * 20 ,r * 20 });
			m_Enviroment[index]->GetTransform()->SetScale(glm::vec2{ 0.25f ,0.25f });
		}
	}
}
