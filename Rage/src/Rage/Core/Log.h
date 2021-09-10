#pragma once

#include "Rage/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace Rage {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RA_CORE_TRACE(...)    ::Rage::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RA_CORE_INFO(...)     ::Rage::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RA_CORE_WARN(...)     ::Rage::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RA_CORE_ERROR(...)    ::Rage::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RA_CORE_CRITICAL(...) ::Rage::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define RA_TRACE(...)         ::Rage::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RA_INFO(...)          ::Rage::Log::GetClientLogger()->info(__VA_ARGS__)
#define RA_WARN(...)          ::Rage::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RA_ERROR(...)         ::Rage::Log::GetClientLogger()->error(__VA_ARGS__)
#define RA_CRITICAL(...)      ::Rage::Log::GetClientLogger()->critical(__VA_ARGS__)
