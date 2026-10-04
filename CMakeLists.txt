cmake_minimum_required(VERSION 3.20)
project(HazelEngine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executables search their own directory for dynamic libraries (.dylib); MacOS specific
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)

# External libraries/modules
#include(FetchContent)
#FetchContent_Declare(
#        spdlog
#        GIT_REPOSITORY [https://github.com/gabime/spdlog.git](https://github.com/gabime/spdlog.git)
#        GIT_TAG v1.0.0
#)
#FetchContent_MakeAvailable(spdlog)
add_subdirectory(Hazel/vendor/spdlog)
add_subdirectory(Hazel/vendor/GLFW)

# Delegate build logic to subfolders
add_subdirectory(Sandbox)
add_subdirectory(Hazel)