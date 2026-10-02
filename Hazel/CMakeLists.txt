project(Hazel CXX)

# Base directory/Subfolder name (bin/Debug-arm64/Hazel/)
set(OUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})

# Hazel Target (.dll / .dylib)
add_library(Hazel SHARED
        src/Hazel.h
        src/Hazel/Core.h
        src/Hazel/EntryPoint.h
        src/Hazel/Log.h
        src/Hazel/Log.cpp
        src/Hazel/Application.h
        src/Hazel/Application.cpp
        src/Hazel/Events/Events.h
        src/Hazel/Events/KeyEvent.h
        src/Hazel/Events/MouseEvent.h
        src/Hazel/Events/ApplicationEvent.h
)

target_include_directories(Hazel PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

target_link_libraries(Hazel PUBLIC spdlog::spdlog)
target_compile_definitions (Hazel PRIVATE
        HZ_PLATFORM_MACOS
        HZ_BUILD_DLL
)