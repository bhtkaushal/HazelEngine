project(Hazel CXX)

# Base directory/Subfolder name (bin/Debug/Hazel/)
set(OUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})

# Hazel Target (.dll / .dylib)
add_library(Hazel SHARED
        src/Hazel/Application.cpp
        src/Hazel/Application.h
        src/Hazel/Core.h
        src/Hazel.h
        src/Hazel/EntryPoint.h
)

target_compile_definitions (Hazel PRIVATE HZ_PLATFORM_MACOS HZ_BUILD_DLL)