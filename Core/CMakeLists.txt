cmake_minimum_required(VERSION 3.24)
project(Core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#---- Install SFML -------#
include(FetchContent)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
)
fetchcontent_makeavailable(sfml)

#----- Include headers -----#
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/class/*)
include_directories(${sfml_SOURCE_DIR}/include)

#------- Add all source files -------#
file(GLOB_RECURSE SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/class/*/*.cpp"
)

#------ Create lib ------#
add_library(Core SHARED ${SOURCES})

#------- Link lib to Core --------#
target_link_libraries(Core PRIVATE Lib sfml-graphics sfml-window sfml-system -static-libstdc++)
target_include_directories(Core PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/class
        ${sfml_SOURCE_DIR}/include
        $<TARGET_PROPERTY:Lib,INTERFACE_INCLUDE_DIRECTORIES>
)

#------ Properties -------#
set_target_properties(Core PROPERTIES
        OUTPUT_NAME "Core"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

#------ Push to server ------#
include(../config.cmake)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET Core
            POST_BUILD
            COMMAND rsync -avz ${SSH_OPT} ${DLL_PATH_CORE} ${SSH_USER}@${SSH_HOST}:${SSH_PATH}
    )
endif ()