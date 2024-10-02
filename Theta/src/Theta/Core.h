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

#ifdef TH_ENABLE_ASSERTS
	#define TH_ASSERT(x, ...) { if(!(x)) { TH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TH_CORE_ASSERT(x, ...) { if(!(x)) { TH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TH_ASSERT(x, ...)
	#define TH_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)