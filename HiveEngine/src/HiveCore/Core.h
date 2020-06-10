#pragma once

#ifdef HV_PLATFORM_WINDOWS
	#ifdef DLL
			#ifdef HV_BUILD_DLL
				#define HIVEAPI __declspec(dllexport)
			#else
				#define HIVEAPI __declspec(dllimport)
			#endif
		#else
	#endif
#endif