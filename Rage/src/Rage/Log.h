#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Rage {

	class RAGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RA_CORE_TRACE(...)    ::Rage::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RA_CORE_INFO(...)     ::Rage::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RA_CORE_WARN(...)     ::Rage::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RA_CORE_ERROR(...)    ::Rage::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RA_CORE_FATAL(...)    ::Rage::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define RA_TRACE(...)	      ::Rage::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RA_INFO(...)	      ::Rage::Log::GetClientLogger()->info(__VA_ARGS__)
#define RA_WARN(...)	      ::Rage::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RA_ERROR(...)	      ::Rage::Log::GetClientLogger()->error(__VA_ARGS__)
#define RA_FATAL(...)	      ::Rage::Log::GetClientLogger()->fatal(__VA_ARGS__)