#pragma once

#include "Core.h"
namespace Hive {

	class HIVEAPI Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	Application* CreateApplication();
}



