#pragma once

#ifdef TH_PLATFORM_WINDOWS
	#ifdef TH_BUILD_DLL
		#define THETA_API __declspec(dllexport)
	#else 
		#define THETA_API __declspec(dllimport)
	#endif // TH_BUILD_DLL
#else
	#error Theta only support Windows OS!
#endif // TH_PLATFORM_WINDOWS

