#pragma once

#ifdef  RA_PLATFORM_WINDOWS

extern Rage::Application* Rage::CreateApplication();

int main(int argc, char** argv)
{
	Rage::Log::Init();
	RA_CORE_WARN("Initialized Log!");
	int a = 5;
	RA_INFO("Hello! Var={0}", a);

	auto app = Rage::CreateApplication();
	app->Run();
	delete app;
}

#endif //  RA_PLATFORM_WINDOWS

