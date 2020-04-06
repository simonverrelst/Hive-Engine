#pragma once

#ifdef HV_PLATFORM_WINDOWS
	#ifdef HV_BUILD_DLL
		#define HIVEAPI __declspec(dllexport)
	#else
		#define HIVEAPI __declspec(dllimport)
	#endif
#else
	#error Hive engine only supports windows platform  
#endif