#include "study/logstream.hpp"
#include <sstream>
#include <gtest/gtest.h>
#include "study/io.hpp"

TEST(LogStream, DefaultConstructor)
{
	study::LogStream log;
	EXPECT_FALSE(log.has_ostream()) << "LogStream incorrectly marked as connected.";
}

TEST(LogStream, ExplicitConstructor)
{
	std::stringstream ss;
	study::LogStream log(ss);
	EXPECT_TRUE(log.has_ostream()) << "LogStream connection reported incorrectly.";
}

TEST(LogStream, ConnectToOStream)
{
	std::stringstream ss;
	study::LogStream log;
	EXPECT_FALSE(log.has_ostream()) << "LogStream incorrectly marked as connected.";
	EXPECT_EQ(&log.connect_to_ostream(ss), &log) << "Fluid interface error.";
	EXPECT_TRUE(log.has_ostream()) << "LogStream connection reported incorrectly.";
}

TEST(LogStream, ScreenWidth)
{
	study::LogStream log;
	EXPECT_EQ(&log.set_screen_width(60), &log) << "Fluid interface error.";
	EXPECT_EQ(log.get_screen_width(), 60) << "Incorrect screen width reported.";
}

TEST(LogStream, Prefix)
{
	study::LogStream log;
	EXPECT_EQ(&log.set_prefix(":3"), &log) << "Fluid interface error.";
	EXPECT_EQ(log.get_prefix(), ":3") << "Incorrect prefix reported.";
}

TEST(LogStream, SimpleOutput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	log.set_prefix("| ");
	log << "Hello World!" << study::endl;
	EXPECT_EQ(ss.str(), "| Hello World!\n") << "Insertion into LogStream failed.";
}

TEST(LogStream, ComplexInput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	std::string s = " true is ";
	log.set_prefix("| ");
	log << "I'm " << 0 << ',' << s << true << study::endl;
	EXPECT_EQ(ss.str(), "| I'm 0, true is 1\n") << "Insertion into LogStream failed.";
}

TEST(LogStream, LongInput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	log.set_screen_width(64);
	log.set_prefix("| ");
	std::string expected =
"| And the householders were troubled when they noticed that in a\n"
"| ll the village there was not a cat to be found. From each hear\n"
"| th the familiar cat had vanished; cats large and small, black,\n"
"|  grey, striped, yellow and white.\n";
	log << "And the householders were troubled when they noticed that "
	    << "in all the village there was not a cat to be found. From each hearth "
		<< "the familiar cat had vanished; cats large and small, black, grey, "
		<< "striped, yellow and white." << study::endl;
	EXPECT_EQ(ss.str(), expected) << "Format error.";
	// H. P. Lovecraft, The Cats of Ulthar
}

TEST(LogStream, MultiLineInput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	log.set_prefix("| ");
	std::string expected =
"| a = 5\n"
"| b = -1\n"
"| c = a * b = -5\n";
	log << "a = " << 5 << '\n'
	    << "b = " << -1 << '\n'
	    << "c = a * b = " << (5*-1)
	    << study::endl;
	EXPECT_EQ(ss.str(), expected) << "Format error.";
}

TEST(LogStream, MultipleInput)
{
	std::stringstream ss;
	study::LogStream log(ss);
	log.set_prefix("| ");
	std::string expected = "| Here.\n| There.\n";
	log << "Here." << study::endl;
	log << "There." << study::endl;
	EXPECT_EQ(ss.str(), expected) << "Format error.";
}

TEST(LogStream, Flush)
{
	std::stringstream ss;
	study::LogStream log(ss);
	log.set_prefix("| ");
	std::string expected = "| ***\n| ***\n";
	log << "***\n***";
	log.flush();
	EXPECT_EQ(ss.str(), expected) << "Format error.";
}

