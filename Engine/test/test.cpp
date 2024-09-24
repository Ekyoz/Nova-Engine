#include <iostream>
#include <Engine.hpp>
#include <Wrapper.hpp>

int main(int argc, char* argv[])
{
	Entity *entity = createEntity();
	Texture *t = createTexture("/Users/alexandre/Documents/Dev/Projets/Nova Engine/Engine/assets/nova-logo.png");
	addComponent(entity, t);
	run();
	return 0;
}
