cmake_minimum_required(VERSION 3.24)
project(Lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#----- Include headers -----#
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/class/*)

#------- Add all source files -------#
file(GLOB_RECURSE SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/class/*/*.cpp"
)

#------ Create lib ------#
add_library(Lib STATIC ${SOURCES})

#------- Link lib to Core --------#
target_include_directories(Lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/class
)

#------ Properties ------#
set_target_properties(Lib PROPERTIES
        OUTPUT_NAME "Lib"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)