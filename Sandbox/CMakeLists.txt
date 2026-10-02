project(Sandbox CXX)

# Base directory/Subfolder name (bin/Debug/Sandbox/)
set(OUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})

# Sandbox Target (.exe)
add_executable(Sandbox
        src/Sandbox.cpp
)
# Link the Hazel library target into Sandbox; add Hazel/src for Hazel.h;
target_link_libraries(Sandbox PRIVATE Hazel)
target_include_directories(Sandbox PRIVATE "${CMAKE_SOURCE_DIR}/Hazel/src")
target_link_libraries(Sandbox PUBLIC spdlog::spdlog)

# Automatically copy Hazel.dll to Sandbox's output directory
add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Hazel>
        $<TARGET_FILE_DIR:Sandbox>
)

target_compile_definitions(Sandbox PRIVATE HZ_PLATFORM_MACOS)
target_link_libraries(Sandbox PRIVATE Hazel)