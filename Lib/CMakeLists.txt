# Lib/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Nom de la bibliothèque
project(Lib)

# Créer une bibliothèque statique à partir des fichiers source
add_library(Lib STATIC src/lib.cpp)

# Ajouter tous les fichiers .cpp dans le dossier class
file(GLOB_RECURSE CLASS_SOURCES class/*/*.cpp)
file(GLOB_RECURSE CLASS_HEADERS class/*/*.hpp)

# Définir les répertoires d'inclusion
target_sources(Lib PRIVATE ${CLASS_SOURCES})
target_include_directories(Lib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/class>
)

set_target_properties(Lib PROPERTIES
        OUTPUT_NAME "Lib"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

#include(../config.cmake)
#if(CMAKE_BUILD_TYPE STREQUAL "Release")
#    add_custom_command(TARGET Lib
#            POST_BUILD
#            COMMAND rsync -avz ${SSH_OPT} ${DLL_PATH_ENGINE} ${SSH_USER}@${SSH_HOST}:${SSH_PATH}
#    )
#endif ()