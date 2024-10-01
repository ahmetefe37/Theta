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
		WindowResizeEvent e(640,480);
		TH_INFO("---------------------------------------");
		
		TH_INFO("App Resolution : x = {0}", e.GetWidth());
		TH_INFO("App Resolution : y = {0}", e.GetHeight());
		TH_INFO("App Name = {0}", e.GetName());
		TH_INFO("is in category? = {0}", e.IsInCategory(EventCategoryApplication));
		TH_INFO("is in category? = {0}", e.IsInCategory(EventCategoryInput));
		
		TH_INFO("---------------------------------------");

		/*if (e.IsInCategory(EventCategoryApplication)) {
			TH_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			TH_TRACE(e);
		}*/



		while (true);
	}
}