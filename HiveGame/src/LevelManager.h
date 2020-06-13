#pragma once
#include "HiveComponents/Component.h"
#include "HiveHelpers/BinaryReader.h"
#include <vector>
#include <string>

class Hive::GameObject;

class LevelManager : public Hive::Component
{
public:
	LevelManager(const std::string & levelFile, const std::string & enemyFile);
	virtual ~LevelManager();
public:
	void Start() override;

	void NextLevel();

	void AddLevelToScene();

	int m_CurrentLevel{};


	
private:
	Hive::BinaryReader m_Reader;

	std::vector<std::vector<bool>> m_Levels;

	std::vector<Hive::GameObject*> m_Enviroment;

	const int m_AmountOfCols = 32;
	const int m_AmountOfRows = 25;
	const int m_AmountOfLevels = 100;

	std::string m_LevelFilePath;
	std::string m_EnemyfilePath;


};

