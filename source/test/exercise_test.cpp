#include "study/exercise.hpp"
#include <gtest/gtest.h>
#include <string>

using namespace study;

TEST(Exercise, Constructor)
{
	Exercise e("Test.");
}

TEST(Exercise, Args)
{
	Exercise e("ArgTest");
	e.add_arg("Arg1").add_arg("Arg2").add_arg("Arg3");
	auto args = e.get_args();
	EXPECT_STREQ(args[0], "ArgTest");
	EXPECT_STREQ(args[1], "Arg1");
	EXPECT_STREQ(args[2], "Arg2");
	EXPECT_STREQ(args[3], "Arg3");
}

struct StringComparisonTestStruct
{
	bool operator()(std::string const& a, std::string const& b)
	{
		return a == b;
	}
};

TEST(Exercise, Functor)
{
	StringComparisonTestStruct st;
	Exercise e("FunctorTest");
	e.set_compare(st);
	ASSERT_TRUE(e.get_compare()) << "Functor not present.";
	ASSERT_TRUE(e.get_compare()("Hello", "Hello")) << "Incorrect comparison.";
	ASSERT_FALSE(e.get_compare()("Hello", "Good-bye")) << "Incorrect comparison.";
}
