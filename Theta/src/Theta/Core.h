#pragma once

// #ifdef TH_PLATFORM_WINDOWS
// 	#ifdef TH_BUILD_DLL
// 		#define THETA_API __declspec(dllexport)
// 	#else 
// 		#define THETA_API __declspec(dllimport)
// 	#endif // TH_BUILD_DLL
// #else
// 	#error Theta only support Windows OS!
// #endif // TH_PLATFORM_WINDOWS

#ifdef _WIN32  // Check if we are on a Windows platform
    #ifdef TH_BUILD_DLL
        #define THETA_API __declspec(dllexport)
    #else
        #define THETA_API __declspec(dllimport)
    #endif // TH_BUILD_DLL
#elif defined(__linux__)  // Check if we are on a Linux platform
    #ifdef TH_BUILD_DLL
        #define THETA_API __attribute__((visibility("default")))  // Use visibility attribute for Linux
    #else
        #define THETA_API
    #endif
#else
    #error Theta only supports Windows and Linux!
#endif // Platform check


// Assertation Macros

// Platform-specific debug break function
#ifdef _WIN32
    #define DEBUG_BREAK() __debugbreak()  // Use Windows-specific debug break
#elif defined(__linux__)
    #include <signal.h>
    #define DEBUG_BREAK() raise(SIGTRAP)  // Use Linux-specific debug break
#else
    #define DEBUG_BREAK()  // No-op or other platform-specific implementation
#endif

#ifdef TH_ENABLE_ASSERTS
    #define TH_ASSERT(x, ...) { if(!(x)) { TH_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK(); } }
    #define TH_CORE_ASSERT(x, ...) { if(!(x)) { TH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK(); } }
#else
    #define TH_ASSERT(x, ...)
    #define TH_CORE_ASSERT(x, ...)
#endif

// #ifdef TH_ENABLE_ASSERTS
// 	#define TH_ASSERT(x, ...) { if(!(x)) { TH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
// 	#define TH_CORE_ASSERT(x, ...) { if(!(x)) { TH_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
// #else
// 	#define TH_ASSERT(x, ...)
// 	#define TH_CORE_ASSERT(x, ...)
// #endif


#define BIT(x) (1 << x)