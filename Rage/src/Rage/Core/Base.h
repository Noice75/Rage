#pragma once

#include <memory>

#include "Rage/Core/PlatformDetection.h"

#ifdef RA_DEBUG
	#if defined(RA_PLATFORM_WINDOWS)
		#define RA_DEBUGBREAK() __debugbreak()
	#elif defined(RA_PLATFORM_LINUX)
		#include <signal.h>
		#define RA_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define RA_ENABLE_ASSERTS
#else
	#define RA_DEBUGBREAK()
#endif

#define RA_EXPAND_MACRO(x) x
#define RA_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define RA_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Rage {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Rage/Core/Log.h"
#include "Rage/Core/Assert.h"
