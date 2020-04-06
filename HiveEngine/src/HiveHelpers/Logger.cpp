#include "Logger.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Hive
{
	std::shared_ptr<spdlog::logger> Logger::pEngineLogger = nullptr;
	std::shared_ptr<spdlog::logger> Logger::pAppLogger = nullptr;

	void Logger::Init() {
		// Time stamp/ name of logger / color / message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		pEngineLogger = spdlog::stdout_color_mt("HIVE ENGINE");
		pEngineLogger->set_level(spdlog::level::trace);
		pAppLogger = spdlog::stdout_color_mt("GAME");
		pAppLogger->set_level(spdlog::level::trace);
	}
}




