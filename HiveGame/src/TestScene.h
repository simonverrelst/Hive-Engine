#pragma once
#include "HiveScene/Scene.h"

class LevelManager;

class TestScene final :	public Hive::Scene
{
public:
	TestScene();
	virtual ~TestScene() =default;
protected:
	void Start() override;

	void Update() override;

	void Render() const override;
private:
	LevelManager* m_pLevelManager;
};

