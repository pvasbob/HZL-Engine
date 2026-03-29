#pragma once

#ifdef HZL_PLATFORM_WINDOWS
	#ifdef HZL_BUILD_DLL 	
		#define HZL_API __declspec(dllexport)
	#else
		#define HZL_API __declspec(dllimport)
	#endif
#else 
	#error Hazel only supports Windows!
#endif
