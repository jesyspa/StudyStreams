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

unsigned int fibo(unsigned int i)
{
	if (i < 2)
		return i;
	else
		return fibo(i-1) + fibo(i-2);
}

} // namespace

class FibonacciTest :
	public LessonMock
{
  public:
	void construct()
	{
		log().set_prefix("");
		boost::mt19937 gen;
		gen.seed(std::time(0));
		boost::uniform_int<> dist(1,16);
		boost::variate_generator<
			boost::mt19937&,
			boost::uniform_int<>
		> roll(gen, dist);
		std::cout << "Using: ";
		for (unsigned int i = 0; i < 4; ++i) {
			int j = roll();
			std::cout << j << ' ';
			add_exercise(new Exercise(
				boost::lexical_cast<std::string>(j),
				boost::lexical_cast<std::string>(fibo(j)),
				boost::lexical_cast<std::string>(j))
			);
		}
		std::cout << std::endl;
	}
};

TEST(FibonacciTest, Check)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface lesson(new FibonacciTest, in, log, out);
		while (lesson) {
			int i;
			EXPECT_TRUE(in >> i);
			out << fibo(i) << endl;
		}
	}
	EXPECT_EQ("SSSS\n", ss.str());
}

