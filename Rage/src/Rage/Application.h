#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Rage
{
	class RAGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	// Define in client
	Application* CreateApplication();
}


