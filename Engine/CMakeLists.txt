cmake_minimum_required(VERSION 3.24)
project(Engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#----- Include headers -----#
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/wrapper)

#------- Add all source files -------#
file(GLOB_RECURSE SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wrapper/*.hpp"
)

#------ Create lib ------#
add_library(Engine SHARED ${SOURCES})

#------- Link lib to Core --------#
target_link_libraries(Engine PRIVATE Lib Core -static-libstdc++)
target_include_directories(Engine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/wrapper
)

#------ Properties -------#
set_target_properties(Engine PROPERTIES
        OUTPUT_NAME "Engine"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

#------ Push to server ------#
include(../config.cmake)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET Engine
            POST_BUILD
            COMMAND rsync -avz ${SSH_OPT} ${DLL_PATH_ENGINE} ${SSH_USER}@${SSH_HOST}:${SSH_PATH}
    )
endif ()