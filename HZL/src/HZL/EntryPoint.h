#pragma once

#ifdef HZL_PLATFORM_WINDOWS

HZL::Application* HZL::CreateApplication();

int main(int argc, char** argv) {

	printf("HZL Engine.");
	//HZL::Application* sandbox = CreateApplication();
	auto app = HZL::CreateApplication();
	app->Run();
	delete app;
}
#endif
