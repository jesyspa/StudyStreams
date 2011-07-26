#include <gtest/gtest.h>
#include <sstream>
#include "study/lesson.hpp"
#include "study/lessonloader.hpp"
#include "study/io.hpp"

using namespace study;

class StagesTestLoader :
	public LessonLoader
{
  public:
	StagesTestLoader(unsigned int i) : i_(i) {}

	void construct()
	{
		log().set_prefix("");
		log() << "C";
		for (unsigned int i = 0; i < i_; ++i)
			add_exercise_at_end(new Exercise(""));
	}
	void welcome() { log() << "W"; }
	void start_exercise() { log() << "S"; }
	void end_exercise() { log() << "E"; }
	void part() { log() << "P"; }
	void destruct() { log() << "D" << study::endl; }

  private:
	unsigned int i_;
};

TEST(StagesTestLoader, Zero)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		Lesson l(new StagesTestLoader(0), in, log, out);
		while(l)
			out.flush();
	}
	EXPECT_EQ("CWPD\n", ss.str());
}

TEST(StagesTestLoader, One)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		Lesson l(new StagesTestLoader(1), in, log, out);
		while(l)
			out.flush();
	}
	EXPECT_EQ("CWSEPD\n", ss.str());
}

TEST(StagesTestLoader, Three)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		Lesson l(new StagesTestLoader(3), in, log, out);
		while(l)
			out.flush();
	}
	EXPECT_EQ("CWSESESEPD\n", ss.str());
}

