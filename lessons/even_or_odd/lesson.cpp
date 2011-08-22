#include <ctime>
#include <boost/lexical_cast.hpp>
#include <study/lessoninterface.hpp>
#include <study/linearlesson.hpp>
#include <study/guardedexercise.hpp>

using namespace study;

struct EvenOrOddLesson :
	public LinearLesson
{
	void construct()
	{
		log().set_prefix("--| ");
		boost::mt19937 gen;
		gen.seed(std::time(0));
		boost::uniform_int<> dist(-5000, 5000);
		boost::variate_generator<
			boost::mt19937&,
			boost::uniform_int<>
		> roll(gen, dist);
		for (size_t n = 0; n < 16; ++n) {
			int j = roll();
			auto name = boost::lexical_cast<std::string(n);
			add_exercise(&(new Exercise(name))->
				set_input(boost::lexical_cast<std::string>(j)).
				set_answer(j ? "Even" : "Odd").
				set_compare(loose_compare)
			);
		}
	}

	void welcome()
	{
		log() << "Start of Even or Odd lesson.\n" << study::endl;
	}

	void part()
	{
		log() << "End of lesson." << study::endl;
	}

};

LessonInterface even_or_odd(new EvenOrOddLesson);

