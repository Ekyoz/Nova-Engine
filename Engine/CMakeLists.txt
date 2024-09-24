# Engine/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Nom de la bibliothèque
project(Engine)

# Créer une bibliothèque statique à partir des fichiers source
add_library(Engine SHARED src/Engine.cpp)

# Spécifier que Engine dépend de Core
target_link_libraries(Engine PRIVATE Lib Core -static-libstdc++)

# Ajouter tous les fichiers .cpp dans le dossier class
file(GLOB_RECURSE WRAPPER_SOURCES wrapper/*.cpp)

# Définir les répertoires d'inclusion
target_sources(Engine PRIVATE ${WRAPPER_SOURCES})
target_include_directories(Engine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/wrapper>
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/wrapper>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../Lib/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../Core/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../cmake-build-${CMAKE_BUILD_TYPE}/_deps/sdl2-src/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../cmake-build-${CMAKE_BUILD_TYPE}/_deps/sdl2_image-src/include>
)

set_target_properties(Engine PROPERTIES
        OUTPUT_NAME "Engine"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

include(../config.cmake)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET Engine
            POST_BUILD
            COMMAND rsync -avz ${SSH_OPT} ${DLL_PATH_ENGINE} ${SSH_USER}@${SSH_HOST}:${SSH_PATH}
    )
endif ()

# Ajouter des tests si nécessaire
enable_testing()
add_subdirectory(test)