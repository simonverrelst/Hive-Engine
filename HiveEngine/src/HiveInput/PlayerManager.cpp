#include "HivePCH.h"
#include "PlayerManager.h"
#include "HiveInput/PlayerInput.h"
#include "HiveHelpers/Logger.h"

void Hive::PlayerManager::Init(size_t amountOfPlayers)
{
	m_pPlayerControllers.resize(amountOfPlayers);
	for	(size_t i = 0; i < amountOfPlayers; i++)
	{
		m_pPlayerControllers[i] = new PlayerController(i);
	}
}

Hive::PlayerManager::~PlayerManager()
{
	for (size_t i = 0; i < m_pPlayerControllers.size(); i++)
	{
		SafeDelete(m_pPlayerControllers[i]);
	}
}

Hive::PlayerController* Hive::PlayerManager::GetPlayerController(size_t id)
{
	if (id < 0 || id > m_pPlayerControllers.size())
	{
		LOG_ENGINE_ERROR("No player controller found out of range");
		return nullptr;
	}

	return m_pPlayerControllers[id];
}