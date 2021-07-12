#pragma once

#include "Core.h"

#include "Window.h"
#include "Rage/LayerStack.h"
#include "Events/Event.h"
#include "Rage/Events/ApplicationEvent.h"

namespace Rage
{
	class RAGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	// Define in client
	Application* CreateApplication();
}


