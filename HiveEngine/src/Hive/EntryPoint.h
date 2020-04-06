#pragma once
#ifdef HV_PLATFORM_WINDOWS

extern Hive::Application* Hive::CreateApplication();

int main(int argc, char** argv) 
{
	argc = 0;
	argv = nullptr;
	auto app = Hive::CreateApplication();
	app->Run();
	delete app;
}

#endif