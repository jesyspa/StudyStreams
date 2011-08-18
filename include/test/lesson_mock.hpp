#ifndef INCLUDE_TEST_LESSON_MOCK_HPP
#define INCLUDE_TEST_LESSON_MOCK_HPP

#include "study/linearlesson.hpp"
#include "study/exercise.hpp"

namespace study
{

//! \brief Mock class for Lesson.
class LessonMock :
	public LinearLesson
{
  public:
	void construct()
	{
		log().set_prefix("[ ");
	}
	void welcome() {}
	void end_exercise(int /*retval*/, std::string const& answer)
	{
		auto& e = get_exercise();
		if (e.get_compare()(answer, e.get_answer())) {
			log() << "S";
		} else { 
			log() << "F";
		}
	}

	void part() {
		log() << study::endl;
	}

	//! \brief Add an exercise that expects a certain input.
	void expect(std::string const& s)
	{
		// Magically adds some details, then takes the address of the last returned.
		add_exercise(&(new Exercise("Expected"))->set_answer(s));
	}
};


} // namespace study

#endif // INCLUDE_TEST_LESSON_MOCK_HPP
