#include "thpch.h"

#include "Application.h"
#include "Events/AppllicationEvent.h"
#include "Theta/Log.h"

#include "iostream"

namespace Theta 
{

	Application::Application()
	{

	}
	
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1366,768);
		TH_INFO("---------------------------------------");
		TH_INFO("App Resolution : x = {0}", e.GetWidth());
		TH_INFO("App Resolution : y = {0}", e.GetHeight());
		TH_INFO("---------------------------------------");

		
		if (e.IsInCategory(EventCategoryApplication)) {
			TH_WARN(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput)) {
			TH_WARN(e.ToString());
		}



		while (true);
	}
}