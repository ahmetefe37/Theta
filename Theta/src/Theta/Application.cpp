#include "thpch.h"

#include "Application.h"
#include "Events/AppllicationEvent.h"

namespace Theta 
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	
	Application::~Application()
	{

	}

	void Application::Run()
	{
		/*WindowResizeEvent e(1366,768);
		TH_INFO("---------------------------------------");
		TH_INFO("Window Resolution : {0} - {1}", e.GetWidth(), e.GetHeight());
		TH_INFO("---------------------------------------");*/

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}