#pragma once


#include <Hive.h>


class HiveGame final : public Hive::Application
{

public:
	HiveGame();

	~HiveGame();

	void Start() override;

	void Update() override;

	void Render() override;

};

Hive::Application* Hive::CreateApplication()
{
	return new HiveGame();
}