#pragma once

enum GameEvent
{
	EVENT_PLAYER_DEATH,
	EVENT_LOSE_GAME,
	EVENT_KILL_ENEMY
};



class GameObject;

class Observer 
{
public:
	virtual ~Observer() {}
	virtual void OnNotify(GameObject* object, GameEvent event) = 0;

};

class GameEventObserver : public Observer
{
	virtual void OnNotify(GameObject* object, GameEvent event)
	{
		UNREFERENCED_PARAMETER(object);

		switch (event)
		{
		case EVENT_PLAYER_DEATH:
			break;
		case EVENT_LOSE_GAME:
			break;
		case EVENT_KILL_ENEMY:
			break;
		default:
			break;
		}
	}
};


