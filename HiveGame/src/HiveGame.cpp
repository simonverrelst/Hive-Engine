#include <Hive.h>

class HiveGame : public Hive::Application {
public:
	HiveGame() {

	}

	~HiveGame() {

	}

};

Hive::Application* Hive::CreateApplication() {
	return new HiveGame();
}