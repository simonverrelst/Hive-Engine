#include "HivePCH.h"
#include "PlayerInput.h"

Hive::PlayerController::PlayerController(size_t playerID)
	:m_PlayerActions{}
	,m_PlayerID{playerID}
{

}

Hive::PlayerController::~PlayerController()
{
	for (auto & command : m_PlayerActions)
	{
		SafeDelete(command.second);
	}
}

void Hive::PlayerController::AddCommand(size_t actionID, Command * command)
{
	m_PlayerActions.try_emplace(actionID, command);
}

bool Hive::PlayerController::WasActionPerformed(size_t actionID)
{
	return m_PlayerActions.at(actionID)->Execute();
}
