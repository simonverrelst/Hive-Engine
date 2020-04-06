#pragma once
#include "../HiveCore/Core.h"
#include <spdlog/spdlog.h>

#pragma warning( disable: 4251 )

namespace Hive
{
	class HIVEAPI Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return pEngineLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return pAppLogger; };

	private:
		static std::shared_ptr<spdlog::logger> pEngineLogger;
		static std::shared_ptr<spdlog::logger> pAppLogger;
	};
}

//APP LOG MACROS
#define LOG_ERROR(...)  ::Hive::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_WARN(...)   ::Hive::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...)   ::Hive::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...)  ::Hive::Logger::GetEngineLogger()->trace(__VA_ARGS__)

// ENGINE LOG MACROS
#define LOG_ENGINE_ERROR(...) ::Hive::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_ENGINE_WARN(...)  ::Hive::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_ENGINE_INFO(...)  ::Hive::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_ENGINE_TRACE(...) ::Hive::Logger::GetEngineLogger()->trace(__VA_ARGS__)

