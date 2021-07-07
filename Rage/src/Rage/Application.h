#pragma once
#include "Core.h"
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


