#include "rapch.h"
#include "Rage/Core/Window.h"

#ifdef RA_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Rage
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef RA_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		RA_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}