#pragma once

#include "Rage/Core/Base.h"
#include "Rage/Core/Log.h"
#include <filesystem>

#ifdef RA_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define RA_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { RA##type##ERROR(msg, __VA_ARGS__); RA_DEBUGBREAK(); } }
	#define RA_INTERNAL_ASSERT_WITH_MSG(type, check, ...) RA_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define RA_INTERNAL_ASSERT_NO_MSG(type, check) RA_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", RA_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define RA_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define RA_INTERNAL_ASSERT_GET_MACRO(...) RA_EXPAND_MACRO( RA_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, RA_INTERNAL_ASSERT_WITH_MSG, RA_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define RA_ASSERT(...) RA_EXPAND_MACRO( RA_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define RA_CORE_ASSERT(...) RA_EXPAND_MACRO( RA_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define RA_ASSERT(...)
	#define RA_CORE_ASSERT(...)
#endif
