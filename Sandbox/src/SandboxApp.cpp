#include <Rage.h>
#include <Rage/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Rage::Application
{
public:
	Sandbox(Rage::ApplicationCommandLineArgs args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Rage::Application* Rage::CreateApplication(Rage::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
