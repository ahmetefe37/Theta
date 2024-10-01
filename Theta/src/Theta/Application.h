#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Theta {


	class THETA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};

	Application* CreateApplication();

}
