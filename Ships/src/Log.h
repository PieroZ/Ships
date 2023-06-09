#pragma once

#include <memory>

#include "spdlog/spdlog.h"

namespace Ships {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}

// Core log macros
#define LOG_TRACE(...)    ::Ships::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)     ::Ships::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_WARNING(...)     ::Ships::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Ships::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Ships::Log::GetCoreLogger()->critical(__VA_ARGS__)
