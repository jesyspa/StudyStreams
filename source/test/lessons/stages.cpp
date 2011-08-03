#include <gtest/gtest.h>
#include <sstream>
#include "study/lessoninterface.hpp"
#include "test/lesson_mock.hpp"
#include "study/io.hpp"

using namespace study;

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
			add_exercise(new Exercise(""));
	}
	void welcome() { log() << "W"; }
	void start_exercise() { log() << "S"; }
	void end_exercise(std::string const&) { log() << "E"; }
	void part() { log() << "P"; }
	void destruct() { log() << "D" << study::endl; }

  private:
	unsigned int i_;
};

TEST(StagesTest, Zero)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface l(new StagesTest(0), in, log, out);
		while(l)
			out.flush();
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
		while(l)
			out.flush();
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
		while(l)
			out.flush();
	}
	EXPECT_EQ("CWSESESEPD\n", ss.str());
}

