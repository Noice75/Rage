#include <Rage.h>

class ExampleLayer : public Rage::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Rage::Input::IsKeyPressed(RA_KEY_TAB))
			RA_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Rage::Event& event) override
	{
		if (event.GetEventType() == Rage::EventType::KeyPressed)
		{
			Rage::KeyPressedEvent& e = (Rage::KeyPressedEvent&)event;
			if (e.GetKeyCode() == RA_KEY_TAB)
				RA_TRACE("Tab key is pressed (event)!");
			RA_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};


class Sandbox : public Rage::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Rage::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Rage::Application* Rage::CreateApplication()
{
	return new Sandbox();
}