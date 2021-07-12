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
		RA_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rage::Event& event) override
	{
		RA_TRACE("{0}", event);
	}

};


class Sandbox : public Rage::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Rage::Application* Rage::CreateApplication()
{
	return new Sandbox();
}