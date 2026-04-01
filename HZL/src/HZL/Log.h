#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace  HZL {

	class HZL_API  Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		// inline variable requires at least /std:C++17
		//inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
		//inline static std::shared_ptr<spdlog::logger> s_ClientLogger;

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

		// MUST NOT be initiated here as any .cpp which include the .h will have initiation of these two 
	    // static variables, Linker will complain.
		//std::shared_ptr<spdlog::logger> s_CoreLogger;
		//std::shared_ptr<spdlog::logger> s_ClientLogger;

}


// Core log macros
#define HZL_CORE_TRACE(...)   ::HZL::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define HZL_CORE_INFO(...)    ::HZL::Log::GetCoreLogger()->info(__VA_ARGS__);
#define HZL_CORE_WARN(...)    ::HZL::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define HZL_CORE_ERROR(...)   ::HZL::Log::GetCoreLogger()->error(__VA_ARGS__);
#define HZL_CORE_FATAL(...)   ::HZL::Log::GetCoreLogger()->fatal(__VA_ARGS__);


// Client log macros
#define HZL_TRACE(...)        ::HZL::Log::GetClientLogger()->trace(__VA_ARGS__);
#define HZL_INFO(...)         ::HZL::Log::GetClientLogger()->info(__VA_ARGS__);
#define HZL_WARN(...)         ::HZL::Log::GetClientLogger()->warn(__VA_ARGS__);
#define HZL_ERROR(...)        ::HZL::Log::GetClientLogger()->error(__VA_ARGS__);
#define HZL_FATAL(...)        ::HZL::Log::GetClientLogger()->fatal(__VA_ARGS__);



