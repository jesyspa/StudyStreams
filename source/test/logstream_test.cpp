#include "study/logstream.hpp"
#include "study/io.hpp"
#include "study/stringutils.hpp"
#include <gtest/gtest.h>
#include <sstream>

using namespace study;

TEST(LogStream, DefaultConstructor)
{
	LogStream log;
	EXPECT_FALSE(log.has_ostream()) << "LogStream incorrectly marked as connected.";
}

TEST(LogStream, ExplicitConstructor)
{
	std::stringstream ss;
	LogStream log(ss);
	EXPECT_TRUE(log.has_ostream()) << "LogStream connection reported incorrectly.";
}

TEST(LogStream, ConnectToOStream)
{
	std::stringstream ss;
	LogStream log;
	EXPECT_FALSE(log.has_ostream()) << "LogStream incorrectly marked as connected.";
	EXPECT_EQ(&log.connect_to_ostream(ss), &log) << "Fluid interface error.";
	EXPECT_TRUE(log.has_ostream()) << "LogStream connection reported incorrectly.";
}

TEST(LogStream, SimpleOutput)
{
	std::stringstream ss;
	LogStream log(ss);
	log << "Hello World!" << endl;
	EXPECT_EQ(ss.str(), "Hello World!\n") << "Insertion into LogStream failed.";
}

TEST(LogStream, ComplexInput)
{
	std::stringstream ss;
	LogStream log(ss);
	std::string s = " true is ";
	log << "I'm " << 0 << ',' << s << true << endl;
	EXPECT_EQ(ss.str(), "I'm 0, true is 1\n") << "Insertion into LogStream failed.";
}

TEST(LogStream, LongInput)
{
	std::stringstream ss;
	LogStream log(ss);
	string_format format;
	format.prefix = "| ";
	format.max_width = 64;
	log.set_format_func(format);
	std::string expected =
"| And the householders were troubled when they noticed that in a\n"
"| ll the village there was not a cat to be found. From each hear\n"
"| th the familiar cat had vanished; cats large and small, black,\n"
"|  grey, striped, yellow and white.\n";
	log << "And the householders were troubled when they noticed that "
	    << "in all the village there was not a cat to be found. From each hearth "
		<< "the familiar cat had vanished; cats large and small, black, grey, "
		<< "striped, yellow and white." << endl;
	EXPECT_EQ(ss.str(), expected) << "Format error.";
	// H. P. Lovecraft, The Cats of Ulthar
}

TEST(LogStream, MultiLineInput)
{
	std::stringstream ss;
	LogStream log(ss);
	string_format format;
	format.prefix = "| ";
	log.set_format_func(format);
	std::string expected =
"| a = 5\n"
"| b = -1\n"
"| c = a * b = -5\n";
	log << "a = " << 5 << '\n'
	    << "b = " << -1 << '\n'
	    << "c = a * b = " << (5*-1)
	    << endl;
	EXPECT_EQ(ss.str(), expected) << "Format error.";
}

TEST(LogStream, MultipleInput)
{
	std::stringstream ss;
	LogStream log(ss);
	string_format format;
	format.prefix = "| ";
	log.set_format_func(format);
	std::string expected = "| Here.\n| There.\n";
	log << "Here." << endl;
	log << "There." << endl;
	EXPECT_EQ(ss.str(), expected) << "Format error.";
}

TEST(LogStream, Flush)
{
	std::stringstream ss;
	LogStream log(ss);
	string_format format;
	format.prefix = "| ";
	log.set_format_func(format);
	std::string expected = "| ***\n| ***\n";
	log << "***\n***";
	log.flush();
	EXPECT_EQ(ss.str(), expected) << "Format error.";
}

