#pragma once
#include "HiveHelpers/Singleton.h"


#include <vector>

namespace Hive 
{
	class PlayerController;

	class PlayerManager :
		public Singleton<PlayerManager>
	{
	public:
		void Init(size_t amountOfPlayers);

		virtual ~PlayerManager();

		PlayerController * GetPlayerController(size_t id);

		size_t GetAmountOfPlayers() { return m_pPlayerControllers.size(); };

	private:
		std::vector<PlayerController*> m_pPlayerControllers;
	};

}


