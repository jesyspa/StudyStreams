#ifndef INCLUDE_TEST_LESSONLOADER_MOCK_HPP
#define INCLUDE_TEST_LESSONLOADER_MOCK_HPP

#include "study/lessonloader.hpp"

namespace study
{

class Lesson;
class LogStream;
class OutStream;
class InStream;

//! \brief Mock class for LessonLoader.
class LessonLoaderMock :
	public LessonLoader
{
  public:
	void construct() {
		log().set_prefix("[ ");
	}
	void welcome() {}
	void part() {}
};


} // namespace study

#endif // INCLUDE_TEST_LESSONLOADER_MOCK_HPP
