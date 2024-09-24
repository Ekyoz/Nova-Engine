#include "Core.hpp"
#include "Engine.hpp"
#include "Wrapper.hpp"
#include <gtest/gtest.h>

#include "../Lib/class/Component/Texture/Texture.hpp"
#include "../Lib/class/Entity/Entity.hpp"

TEST(NovaTest, TestFonction)
{
	Entity *entity = createEntity();
	Texture *t = createTexture("/Users/alexandre/Documents/Dev/Projets/Nova Engine/Engine/assets/nova-logo.png");
	addComponent(entity, t);
	run();
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
