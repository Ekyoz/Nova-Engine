# Core/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Nom de la bibliothèque
project(Core)

include(FetchContent)

# Télécharger SDL2
FetchContent_Declare(
        SDL2
        URL https://github.com/libsdl-org/SDL/releases/download/release-2.30.7/SDL2-2.30.7.zip
)

# Télécharger SDL2_image
FetchContent_Declare(
        SDL2_image
        URL https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.2/SDL2_image-2.8.2.zip
)

# Télécharger et préparer les dépendances
FetchContent_MakeAvailable(SDL2 SDL2_image)

# Créer une bibliothèque statique à partir des fichiers source
add_library(Core SHARED src/core.cpp)

# Lier SDL2 et SDL2_image à Core
target_link_libraries(Core PRIVATE SDL2 SDL2_image)

# Définir les répertoires d'inclusion
target_include_directories(Core PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        $<TARGET_PROPERTY:SDL2,INTERFACE_INCLUDE_DIRECTORIES>
        $<TARGET_PROPERTY:SDL2_image,INTERFACE_INCLUDE_DIRECTORIES>
)

set_target_properties(Core PROPERTIES
        OUTPUT_NAME "Core"
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

include(../config.cmake)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET Core
            POST_BUILD
            COMMAND rsync -avz ${SSH_OPT} ${DLL_PATH_CORE} ${SSH_USER}@${SSH_HOST}:${SSH_PATH}
    )
endif ()
    
# Ajouter des tests si nécessaire
enable_testing()
add_subdirectory(test)