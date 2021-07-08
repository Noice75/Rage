#pragma once

#ifdef  RA_PLATFORM_WINDOWS

extern Rage::Application* Rage::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rage::CreateApplication();
	app->Run();
	delete app;
}

#endif //  RA_PLATFORM_WINDOWS

