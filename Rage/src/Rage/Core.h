#pragma once

#ifdef RA_PLATFORM_WINDOWS
	#ifdef RA_BUILD_DLL
		#define RAGE_API __declspec(dllexport)
	#else
		#define RAGE_API __declspec(dllimport)
	#endif
#else
	#error RAGE only supports Windows!
#endif

#define BIT(x) (1 << x)