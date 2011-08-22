#include "test/lesson_mock.hpp"
#include "study/solution.hpp"
#include "study/lessoninterface.hpp"
#include "study/io.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

using namespace study;

struct TestSolution :
	Solution
{
	TestSolution(LessonInterface& lesson) :
		Solution(lesson)
	{}

	int solution(int argc, char* argv[]);
};

#define MAIN TestSolution::solution

int MAIN(int /* argc */, char* /* argv */[])
{
	std::string s;
	in() >> s;
	if (s == "Hello")
		out() << "World";
	return 0;
}

struct SolutionLesson :
	LessonMock
{
	SolutionLesson() :
		solution_(0)
	{
		add_exercise(&(new Exercise("SolutionTest"))->
			set_input("Hello").
			set_answer("World")
		);
	}

	void add_solution(Solution& solution)
	{
		solution_ = &solution;
	}

	int solution(int argc, char* argv[]) {
		return solution_->solution(argc, argv);
	}
  private:
  	Solution* solution_;
};

TEST(SolutionTest, Zero)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		auto lesson = new SolutionLesson;
		LessonInterface l(lesson, in, log, out);
		TestSolution solution(l);
		lesson->add_solution(solution);
		l.run();
	}
	EXPECT_EQ("S\n", ss.str());
}
