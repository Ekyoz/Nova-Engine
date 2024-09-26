#include "Core.hpp"
#include "Wrapper.hpp"
#include <gtest/gtest.h>

TEST(NovaTest, TestFonction)
{
	run();
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
