#pragma once

#include "memory"

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Theta
{ 

	class THETA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Logging Macros
#define TH_CORE_TRACE(...) ::Theta::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TH_CORE_INFO(...)  ::Theta::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TH_CORE_WARN(...)  ::Theta::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TH_CORE_ERROR(...) ::Theta::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TH_CORE_FATAL(...) ::Theta::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//Client Logging Macros
#define TH_TRACE(...) ::Theta::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TH_INFO(...)  ::Theta::Log::GetClientLogger()->info(__VA_ARGS__)
#define TH_WARN(...)  ::Theta::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TH_ERROR(...) ::Theta::Log::GetClientLogger()->error(__VA_ARGS__)
#define TH_FATAL(...) ::Theta::Log::GetClientLogger()->fatal(__VA_ARGS__)
