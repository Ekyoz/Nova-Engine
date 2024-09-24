#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <list>
#include <ostream>
#include <Entity/Entity.hpp>
#include <Component/Component/Component.hpp>
#include <Component/Texture/Texture.hpp>

#include "SDL.h"
#include "SDL_image.h"

void setPath(char *path);
void test(std::list<Entity*> entities);

#endif //CORE_HPP
