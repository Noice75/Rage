#pragma once

#include "Core.h"

#include "Window.h"
#include "Rage/LayerStack.h"
#include "Events/Event.h"
#include "Rage/Events/ApplicationEvent.h"

#include "Rage/ImGui/ImGuiLayer.h"
#include "Rage/Renderer/Shader.h"
#include "Rage/Renderer/Buffer.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	private:
		static Application* s_Instance;
	};
	// Define in client
	Application* CreateApplication();
}


