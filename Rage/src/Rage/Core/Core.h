#pragma once

#include <memory>

#ifdef RA_PLATFORM_WINDOWS
#if RA_DYNAMIC_LINK
	#ifdef RA_BUILD_DLL
		#define RAGE_API __declspec(dllexport)
	#else
		#define RAGE_API __declspec(dllimport)
	#endif
#else
    #define RAGE_API
#endif
#else
	#error RAGE only supports Windows!
#endif

#ifdef RA_DEBUG
	#define RA_ENABLE_ASSERTS
#endif

#ifdef RA_ENABLE_ASSERTS
        #define RA_ASSERT(x, ...) { if(!(x)) { RA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
        #define RA_CORE_ASSERT(x, ...) { if(!(x)) { RA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
        #define RA_ASSERT(x, ...)
        #define RA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Rage {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}