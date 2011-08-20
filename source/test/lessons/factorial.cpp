#include <gtest/gtest.h>
#include <sstream>
#include <ctime>
#include <boost/lexical_cast.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include "study/lessoninterface.hpp"
#include "test/lesson_mock.hpp"
#include "study/io.hpp"

using namespace study;

namespace
{

unsigned int fact(unsigned int i)
{
	if (i < 2)
		return 1;
	else
		return i * fact(i-1);
}

} // namespace

// Used in order to make it look more like a typical lesson.
#define MAIN FactorialTest::solution


class FactorialTest :
	public LessonMock
{
  public:
	FactorialTest()
	{
		boost::mt19937 gen;
		gen.seed(std::time(0));
		boost::uniform_int<> dist(0,8);
		boost::variate_generator<
			boost::mt19937&,
			boost::uniform_int<>
		> roll(gen, dist);
		std::cout << "Using: ";
		for (unsigned int i = 0; i < 4; ++i) {
			int j = roll();
			std::cout << j << ' ';
			add_exercise(&(new Exercise(boost::lexical_cast<std::string>(j)))->
				set_input(boost::lexical_cast<std::string>(j)).
				set_answer(boost::lexical_cast<std::string>(fact(j))).
				set_compare(float_compare)
			);
		}
		std::cout << std::endl;
	}

	int solution(int argc, char* argv[]);
};

int MAIN(int /*argc*/, char* /*argv*/[])
{
	int i;
	EXPECT_TRUE(in() >> i);
	out() << fact(i) << endl;
	return 0;
}

TEST(FactorialTest, Check)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface lesson(new FactorialTest, in, log, out);
		lesson.run();
	}
	EXPECT_EQ("SSSS\n", ss.str());
}

