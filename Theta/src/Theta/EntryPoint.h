#pragma once

#ifdef TH_PLATFORM_WINDOWS

extern Theta::Application* Theta::CreateApplication();

int main(int argc, char** argv)
{
	Theta::Log::Init();
	TH_CORE_WARN("Entity Point is Initialized!");
	TH_WARN("Client Logger is Activated!");

	auto app = Theta::CreateApplication();
	app->Run();
	delete app;
}

#endif