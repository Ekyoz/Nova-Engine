cmake_minimum_required(VERSION 3.10)
project(Nova_Engine)

# Ajouter les sous-dossiers
add_subdirectory(Core)
add_subdirectory(Engine)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(Nova_Test tests/main.cpp)

target_link_libraries(Nova_Test PRIVATE Engine Core gtest_main)

