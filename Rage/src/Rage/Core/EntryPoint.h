#pragma once
#include "Rage/Core/Base.h"
#include "Rage/Core/Application.h"

#ifdef RA_PLATFORM_WINDOWS

extern Rage::Application* Rage::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Rage::Log::Init();

	RA_PROFILE_BEGIN_SESSION("Startup", "RageProfile-Startup.json");
	auto app = Rage::CreateApplication({ argc, argv });
	RA_PROFILE_END_SESSION();

	RA_PROFILE_BEGIN_SESSION("Runtime", "RageProfile-Runtime.json");
	app->Run();
	RA_PROFILE_END_SESSION();

	RA_PROFILE_BEGIN_SESSION("Shutdown", "RageProfile-Shutdown.json");
	delete app;
	RA_PROFILE_END_SESSION();
}

#endif
