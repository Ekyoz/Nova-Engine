#include "Core.hpp"
#include "Engine.hpp"
#include <gtest/gtest.h>

TEST(NovaTest, TestFonction)
{
	setPath("/Users/alexandre/Documents/Dev/Projets/Nova Engine/Engine/assets/nova-logo.png");
	test();
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
