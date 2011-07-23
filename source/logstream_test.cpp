#include "study/logstream.hpp"
#include <sstream>
#include <gtest/gtest.h>
#include "study/io.hpp"

TEST(LogStream, DefaultConstructor)
{
	study::LogStream log;
	ASSERT_FALSE(log.has_ostream()) << "LogStream incorrectly marked as connected.";
}

TEST(LogStream, ExplicitConstructor)
{
	std::stringstream ss;
	study::LogStream log(ss);
	ASSERT_TRUE(log.has_ostream()) << "LogStream connection reported incorrectly.";
}

TEST(LogStream, ConnectToOStream)
{
	std::stringstream ss;
	study::LogStream log;
	ASSERT_FALSE(log.has_ostream()) << "LogStream incorrectly marked as connected.";
	ASSERT_EQ(&log.connect_to_ostream(ss), &log) << "Fluid interface error.";
	ASSERT_TRUE(log.has_ostream()) << "LogStream connection reported incorrectly.";
}

TEST(LogStream, ScreenWidth)
{
	study::LogStream log;
	ASSERT_EQ(&log.set_screen_width(60), &log) << "Fluid interface error.";
	ASSERT_EQ(log.get_screen_width(), 60) << "Incorrect screen width reported.";
}

TEST(LogStream, Prefix)
{
	study::LogStream log;
	ASSERT_EQ(&log.set_prefix(":3"), &log) << "Fluid interface error.";
	ASSERT_EQ(log.get_prefix(), ":3") << "Incorrect prefix reported.";
}

TEST(LogStream, SimpleOutput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	log << "Hello World!" << study::endl;
	ASSERT_EQ(ss.str(), "| Hello World!\n") << "Insertion into LogStream failed.";
}

TEST(LogStream, ComplexInput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	std::string s = " true is ";
	log << "I'm " << 0 << ',' << s << true << study::endl;
	ASSERT_EQ(ss.str(), "| I'm 0, true is 1\n") << "Insertion into LogStream failed.";
}
