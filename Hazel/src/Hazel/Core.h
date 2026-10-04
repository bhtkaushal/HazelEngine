#pragma once

#if defined(__APPLE__) && defined(__MACH__)
    #define HZ_PLATFORM_MACOS
#endif

#ifdef HZ_PLATFORM_MACOS
    #define HAZEL_API __attribute__((visibility("default")))
#else
    #error Working on Macs only for now!
#endif

#ifdef HZ_ENABLE_ASSERTS
    #define HZ_ASSERT(x, ...) { if(!(x)) {HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__) __builtin_debugtrap(); } }
    #define HZ_CORE_ASSERT(x, ...) { if(!(x)) {HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__) __builtin_debugtrap(); } }
#else
    #define HZ_ASSERT(x, ...)
    #define HZ_CORE_ASSERT(x, ...)
#endif


#define BIN(x) (1 << x)
