# Engine/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Nom de la bibliothèque
project(Engine)

# Créer une bibliothèque statique à partir des fichiers source
add_library(Engine SHARED src/Engine.cpp)

# Spécifier que Engine dépend de Core
target_link_libraries(Engine PRIVATE Core)

# Ajouter tous les fichiers .cpp dans le dossier class
file(GLOB_RECURSE CLASS_SOURCES class/*/*.cpp)
file(GLOB_RECURSE CLASS_HEADERS class/*/*.hpp)
file(GLOB_RECURSE WRAPPER_SOURCES wrapper/*.cpp)

# Définir les répertoires d'inclusion
target_sources(Engine PRIVATE ${CLASS_SOURCES})
target_sources(Engine PRIVATE ${WRAPPER_SOURCES})
target_include_directories(Engine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/class>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/wrapper>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../Core/include>  # Inclure le dossier d'en-tête de Core
)

set_target_properties(Engine PROPERTIES
        OUTPUT_NAME "Engine"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

include(../config.cmake)
execute_process(COMMAND rsync -avz ${SSH_OPT} ${DLL_PATH_ENGINE} ${SSH_USER}@${SSH_HOST}:${SSH_PATH})

# Ajouter des tests si nécessaire
enable_testing()
add_subdirectory(test)