#include "rapch.h"
#include "Application.h"

#include "Rage/Events/ApplicationEvent.h"
#include "Rage/Log.h"

namespace Rage {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			RA_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			RA_TRACE(e);
		}

		while (true);
	}

}