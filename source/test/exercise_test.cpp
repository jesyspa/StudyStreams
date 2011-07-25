#include "study/exercise.hpp"
#include <gtest/gtest.h>
#include "study/stringutils.hpp"
#include "study/enumutils.hpp"

using namespace study;

TEST(Exercise, DefaultConstructor)
{
	Exercise e;
}

TEST(Exercise, FullConstructor)
{
	Exercise e(
		"Test",
		"This will be a testing exercise.",
		"This was a testing exercise.",
		"",
		"",
		whitespace_ignore_compare
	);
}

TEST(Exercise, Result)
{
	Exercise e(
		"",
		"ABCD"
	);
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
