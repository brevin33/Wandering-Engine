#pragma once
#include "Core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace Wandering {

	class WANDERING_API Log
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


// Core log macros
#define WD_CORE_TRACE(...)    ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WD_CORE_INFO(...)     ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WD_CORE_WARN(...)     ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WD_CORE_ERROR(...)    ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WD_CORE_FATAL(...)    ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define WD_TRACE(...)	      ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WD_INFO(...)	      ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define WD_WARN(...)	      ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WD_ERROR(...)	      ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define WD_FATAL(...)	      ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)