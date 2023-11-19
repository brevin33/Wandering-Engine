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
#define WD_CORE_TRACE(...)    ::Wandering::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WD_CORE_INFO(...)     ::Wandering::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WD_CORE_WARN(...)     ::Wandering::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WD_CORE_ERROR(...)    ::Wandering::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WD_CORE_FATAL(...)    ::Wandering::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define WD_TRACE(...)	      ::Wandering::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WD_INFO(...)	      ::Wandering::Log::GetClientLogger()->info(__VA_ARGS__)
#define WD_WARN(...)	      ::Wandering::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WD_ERROR(...)	      ::Wandering::Log::GetClientLogger()->error(__VA_ARGS__)
#define WD_FATAL(...)	      ::Wandering::Log::GetClientLogger()->fatal(__VA_ARGS__)