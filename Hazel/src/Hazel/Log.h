#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Hazel {
    class HAZEL_API Log {
    public:
        static void Init();
        inline static auto& getCoreLogger() { return CoreLogger; }
        inline static auto& getClientLogger() { return ClientLogger; }
    private:
        inline static std::shared_ptr<spdlog::logger> CoreLogger;
        inline static std::shared_ptr<spdlog::logger> ClientLogger;
    };
}

// CORE logging macros;
#define HZ_CORE_ERROR(...)      ::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_INFO(...)       ::Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...)      ::Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_WARN(...)       ::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_FATAL(...)      ::Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)

// CLIENT logging macros;
#define HZ_ERROR(...)           ::Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_INFO(...)            ::Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_TRACE(...)           ::Hazel::Log::getClientLogger()->trace(__VA_ARGS__)
#define HZ_WARN(...)            ::Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_FATAL(...)           ::Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)