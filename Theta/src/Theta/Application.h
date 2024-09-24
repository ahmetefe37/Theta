#pragma once

#include "Core.h"

namespace Theta {


	class THETA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();


	private:


	};

	Application* CreateApplication();

}
