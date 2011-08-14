#include "study/exercise.hpp"
#include <gtest/gtest.h>
#include "study/stringutils.hpp"
#include "study/enumutils.hpp"

using namespace study;

TEST(Exercise, Constructor)
{
	Exercise e("Test.");
}

TEST(Exercise, Result)
{
	Exercise e("Unnamed");
	e.set_answer("ABCD");
	EXPECT_TRUE(e.result_is(Exercise::State::noinput))
		<< "Exercise marked as having been tried.";
	e.submit("ABCD");
	EXPECT_FALSE(e.result_is(Exercise::State::noinput))
		<< "Exercise marked as not having been tried.";
	EXPECT_TRUE(e.result_is(Exercise::State::success | Exercise::State::complete))
		<< "Exercise not marked as successful and/or complete.";
	e.reset();
	EXPECT_TRUE(e.result_is(Exercise::State::noinput))
		<< "Exercise marked as having been tried.";
	e.submit("DCBA");
	EXPECT_FALSE(e.result_is(Exercise::State::noinput))
		<< "Exercise marked as not having been tried.";
	EXPECT_TRUE(e.result_is(Exercise::State::fail | Exercise::State::complete))
		<< "Exercise not marked as failed and/or complete.";
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
