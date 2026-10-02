#pragma once

#include <string>
#include <functional>
#include <sstream>
#include <ostream>

#ifdef HZ_PLATFORM_MACOS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __attribute__((visibility("default")))
    #else
        #define HAZEL_API __attribute__((visibility("default")))
    #endif
#else
    #error Working on Macs only for now!
#endif

#define BIN(x) (1 << x) 