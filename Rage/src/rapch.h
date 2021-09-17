#pragma once

#include "Rage/Core/PlatformDetection.h"

#ifdef RA_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Rage/Core/Base.h"

#include "Rage/Core/Log.h"

#include "Rage/Debug/Instrumentor.h"

#ifdef RA_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
