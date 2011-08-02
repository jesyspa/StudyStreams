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
	void part() {}

	//! \brief Add an exercise that expects a certain input.
	void expect(std::string const& s)
	{
		using namespace keywords;
		add_exercise(new Exercise("1", _answer=s));
	}
};


} // namespace study

#endif // INCLUDE_TEST_LESSON_MOCK_HPP
