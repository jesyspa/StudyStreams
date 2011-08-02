#ifndef INCLUDE_TEST_LESSON_MOCK_HPP
#define INCLUDE_TEST_LESSON_MOCK_HPP

#include "study/lesson.hpp"

namespace study
{

class LessonInterface;
class LogStream;
class OutStream;
class InStream;

//! \brief Mock class for Lesson.
class LessonMock :
	public Lesson
{
  public:
	void construct() {
		log().set_prefix("[ ");
	}
	void welcome() {}
	void part() {}
};


} // namespace study

#endif // INCLUDE_TEST_LESSON_MOCK_HPP
