#pragma once

#ifdef HZL_PLATFORM_WINDOWS

extern HZL::Application* HZL::CreateApplication();

int main(int argc, char** argv) {

	HZL::Log::Init();
	//HZL::Log::GetCoreLogger()->warn("Initialized Log!");
	HZL_CORE_WARN("Initialized log!");
	//HZL::Log::GetClientLogger()->info("Hello");
	int a = 1;
	int b = 2;
	HZL_INFO("Hello! Var={0}, Exp={1}", a, b );

	printf("HZL Engine.....");
	//HZL::Application* sandbox = CreateApplication();
	auto app = HZL::CreateApplication();
	app->Run();
	delete app;
}
#endif 

