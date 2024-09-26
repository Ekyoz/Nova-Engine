cmake_minimum_required(VERSION 3.10)
project(Nova_Engine)

#----- Add subdirectory for all libraries -----#
add_subdirectory(Core)
add_subdirectory(Engine)
add_subdirectory(Lib)

#------ Install Google Test -------#
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

#------- Create Google Test --------#
add_executable(Nova_Test tests/main.cpp)
target_link_libraries(Nova_Test PRIVATE Core Engine gtest_main)

