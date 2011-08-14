#include <gtest/gtest.h>
#include <sstream>
#include "study/lessoninterface.hpp"
#include "test/lesson_mock.hpp"
#include "study/io.hpp"

using namespace study;

// Used in order to make it look more like a typical lesson.
#define MAIN StagesTest::solution

class StagesTest :
	public LessonMock
{
  public:
	StagesTest(unsigned int i) : i_(i) {}

	void construct()
	{
		log().set_prefix("");
		log() << "C";
		for (unsigned int i = 0; i < i_; ++i)
			add_exercise(new Exercise("StageExercise"));
	}
	void welcome() { log() << "W"; }
	void start_exercise() { log() << "S"; }
	void end_exercise(int /*retval*/, std::string const&) { log() << "E"; }
	void part() { log() << "P"; }
	void destruct() { log() << "D" << study::endl; }

	int solution(int argc, char* argv[]);

  private:
	unsigned int i_;
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
	EXPECT_EQ("CWPD\n", ss.str());
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
	EXPECT_EQ("CWSEPD\n", ss.str());
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
	EXPECT_EQ("CWSESESEPD\n", ss.str());
}

