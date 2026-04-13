#include "HZLpch.h"

#include "Application.h"

#include "HZL/Events/ApplicationEvent.h"
#include "HZL/Log.h"

#include <stdio.h>

namespace HZL {

	Application::Application() {};
	Application::~Application() {};



	void Application::Run() {

		WindowResizeEvent e(1200, 720);

		HZL_TRACE(e.ToString());
		
		while (true)
		{
		//printf("Hello Oren.");
		};

	};
} 