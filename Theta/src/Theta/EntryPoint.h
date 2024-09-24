#pragma once

#ifdef TH_PLATFORM_WINDOWS

extern Theta::Application* Theta::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Theta::CreateApplication();
	app->Run();
	delete app;
}

#endif