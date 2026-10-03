#pragma once

#if defined(__APPLE__) && defined(__MACH__)
    #define HZ_PLATFORM_MACOS
#endif

#ifdef HZ_PLATFORM_MACOS
    #define HAZEL_API __attribute__((visibility("default")))
#else
    #error Working on Macs only for now!
#endif


#define BIN(x) (1 << x) 