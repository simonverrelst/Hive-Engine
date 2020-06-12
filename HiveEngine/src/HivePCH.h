#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

// SDL libs
//#pragma comment(lib, "SDL2/SDL2.lib")
//#pragma comment(lib, "SDL2/SDL2main.lib")
//
//// OpenGL libs
////#pragma comment (lib,"opengl32.lib")
////#pragma comment (lib,"Glu32.lib")
//
//// SDL extension libs 
//#pragma comment(lib, "SDL2/SDL2_image.lib")  
//#pragma comment(lib, "SDL2/SDL2_ttf.lib") 
//#pragma comment(lib, "SDL2/SDL2_mixer.lib")  

// SDL and OpenGL Includes
#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <GL\GLU.h>
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h> 
//#include <SDL_mixer.h> 
//#include "structs.h"

#include <Box2D/Box2D.h>


#ifdef HV_PLATFORM_WINDOWS
	//#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	
#endif

#define SafeDelete(p) if (p) { delete (p); (p) = nullptr; }

