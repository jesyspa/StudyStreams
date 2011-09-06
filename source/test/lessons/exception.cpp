#include "study/lessoninterface.hpp"
#include "test/lesson_mock.hpp"
#include "study/io.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace study;

// Used in order to make it look more like a typical lesson.
#define MAIN ExceptionTest::solution

class ExceptionTest :
	public LessonMock
{
  public:
	ExceptionTest(bool b)
	{
		if (b)
			add_exercise(new Exercise("Good"));
		else
			add_exercise(new Exercise("Bad"));
	}

	void end_exercise(int /*retval*/, std::string const& /*answer*/)
	{	// No need to do anything
	}

	void handle_exception(std::exception& /*e*/)
	{
		log() << "E" << study::endl;
	}

	int solution(int argc, char* argv[]);
};

int MAIN(int /*argc*/, char* argv[])
{
	const int bad_input = 0;
	if (std::string("Good") == argv[0])
		throw std::exception();
	else
		throw bad_input;
	return 0;
}

TEST(ExceptionTest, Caught)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface l(new ExceptionTest(true), in, log, out);
		l.run();
	}
	EXPECT_EQ("E\n", ss.str());
}

TEST(ExceptionTest, UnCaught)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	bool catch_visited = false;
	{
		LessonInterface l(new ExceptionTest(false), in, log, out);
		try {
			l.run();
		}
		catch (int i) {
			catch_visited = true;
		}
	}
	EXPECT_TRUE(catch_visited);
}

