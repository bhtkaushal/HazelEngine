cmake_minimum_required(VERSION 3.20)
project(HazelEngine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Executables search their own directory for dynamic libraries (.dylib); MacOS specific
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)

# Delegate build logic to subfolders
add_subdirectory(Sandbox)
add_subdirectory(Hazel)