


#pragma once
#ifdef HV_PLATFORM_WINDOWS

extern Hive::Application* Hive::CreateApplication();

#undef main 
int main(int argc, char** argv) 
{
	(void)argc;
	(void)argv;

	Hive::Logger::Init();


	auto app = Hive::CreateApplication();
	app->Run();
	delete app;

}

#endif