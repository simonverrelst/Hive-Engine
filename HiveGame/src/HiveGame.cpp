#include <Hive.h>

class HiveGame : public Hive::Application {
public:
	HiveGame() {

	}

	~HiveGame() {

	}


	virtual void Start() override
	{
	
	}

};

Hive::Application* Hive::CreateApplication() {
	return new HiveGame();
}