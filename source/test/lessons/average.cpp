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

// Used in order to make it look more like a typical lesson.
#define MAIN AverageTest::solution

class AverageTest :
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
		std::cout << "Using: \n";
		for (unsigned int i = 0; i < 4; ++i) {
			int j = roll();
			int sum = 0;
			Exercise* e = new Exercise(boost::lexical_cast<std::string>(i));
			std::cout << "[ ";
			for (int k = 0; k < j; ++k) {
				int h = roll();
				sum += h;
				std::cout << h << " ";
				e->append_input(boost::lexical_cast<std::string>(h));
			}
			e->set_answer(boost::lexical_cast<std::string>(sum/j));
			e->set_compare(float_compare);
			add_exercise(e);
			std::cout << " ]\n";
		}
		std::cout << std::endl;
	}

	int solution(int argc, char* argv[]);
};

int MAIN(int /*argc*/, char* /*argv*/[])
{
	int count = 0, sum = 0, t;
	while (in() >> t) {
		count++;
		sum += t;
	}
	out() << (sum / count) << endl;
	return 0;
}

TEST(AverageTest, Check)
{
	std::stringstream ss;
	InStream in;
	LogStream log(ss);
	OutStream out;
	{
		LessonInterface lesson(new AverageTest, in, log, out);
		lesson.run();
	}
	EXPECT_EQ("SSSS\n", ss.str());
}


