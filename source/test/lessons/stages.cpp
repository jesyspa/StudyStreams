#include "study/lessoninterface.hpp"
#include "test/lesson_mock.hpp"
#include "study/io.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace study;

// Used in order to make it look more like a typical lesson.
#define MAIN StagesTest::solution

class StagesTest :
	public LessonMock
{
  public:
	StagesTest(unsigned int k)
	{
		for (unsigned int i = 0; i < k; ++i)
			add_exercise(new Exercise("StageExercise"));
	}
	void welcome() {
		log() << "W";
	}
	void start_exercise() { log() << "S"; }
	void end_exercise(int /*retval*/, std::string const&) { log() << "E"; }
	void part() { log() << "P" << study::endl; }

	int solution(int argc, char* argv[]);
};

int MAIN(int /*argc*/, char* /*argv*/[])
{
	return 0;
}

TEST(StagesTest, Zero)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface l(new StagesTest(0), in, log, out);
		l.run();
	}
	EXPECT_EQ("WP\n", ss.str());
}

TEST(StagesTest, One)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface l(new StagesTest(1), in, log, out);
		l.run();
	}
	EXPECT_EQ("WSEP\n", ss.str());
}

TEST(StagesTest, Three)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface l(new StagesTest(3), in, log, out);
		l.run();
	}
	EXPECT_EQ("WSESESEP\n", ss.str());
}

