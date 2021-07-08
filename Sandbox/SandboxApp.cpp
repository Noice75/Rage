#include <Rage.h>

class Sandbox : public Rage::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Rage::Application* Rage::CreateApplication()
{
	return new Sandbox();
}