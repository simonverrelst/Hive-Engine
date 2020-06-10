#include "HivePCH.h"
#include "HiveHelpers/ResourceManager.h"
#include "HiveRender/Renderer.h"
#include "HiveRender/Texture2D.h"
#include "HiveHelpers/Logger.h"


void Hive::ResourceManager::Init(const std::string& dataPath)
{
	m_DataPath = dataPath;

	// load support for png and jpg, this takes a while!

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) 
	{
		LOG_ENGINE_ERROR(std::string("Failed to load support for png's: ") + SDL_GetError());
	//	throw std::runtime_error(std::string("Failed to load support for png's: ") + SDL_GetError());
	}

	if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) 
	{
		LOG_ENGINE_ERROR(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	//	throw std::runtime_error(std::string("Failed to load support for jpg's: ") + SDL_GetError());
	}

	if (TTF_Init() != 0) 
	{
		LOG_ENGINE_ERROR(std::string("Failed to load support for fonts: ") + SDL_GetError());
	//	throw std::runtime_error(std::string("Failed to load support for fonts: ") + SDL_GetError());
	}
}

Hive::Texture2D* Hive::ResourceManager::LoadTexture(const std::string& file) const
{
	const auto fullPath = m_DataPath + file;
	auto texture = IMG_LoadTexture(Renderer::GetInstance().GetSDLRenderer(), fullPath.c_str());
	if (texture == nullptr)
	{
		throw std::runtime_error(std::string("Failed to load texture: ") + SDL_GetError());
	}
	return new Texture2D(texture);
}

