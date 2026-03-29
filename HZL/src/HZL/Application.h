#pragma once

#include "Core.h"


namespace HZL {

	class HZL_API Application
	{
	public:
		Application();
		virtual	~Application();

		void Run();

	};

	// To be defined in CLIENT.
	Application* CreateApplication();

}

