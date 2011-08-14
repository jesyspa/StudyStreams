#include "study/stringutils.hpp"
#include <gtest/gtest.h>

using namespace study;

TEST(StringUtils, FloatCompare)
{
	EXPECT_TRUE(float_compare("5", "5"));
	EXPECT_FALSE(float_compare("5", "6"));
	EXPECT_TRUE(float_compare("5.0", "5"));
	EXPECT_FALSE(float_compare("4.8", "4.9"));
	EXPECT_TRUE(float_compare("0 4", "0 4"));
	EXPECT_TRUE(float_compare("0 3.5", "0 3.5"));
	EXPECT_FALSE(float_compare("0 3.5", "0 3.5 7"));
	EXPECT_FALSE(float_compare("0 3.5 7", "0 3.5"));
}

