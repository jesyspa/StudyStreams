#ifndef INCLUDE_TEST_LESSON_MOCK_HPP
#define INCLUDE_TEST_LESSON_MOCK_HPP

#include <cassert>
#include <string>
#include <boost/utility.hpp>
#include "study/io.hpp"
#include "study/lesson.hpp"
#include "study/lessonloader.hpp"
#include "test/lessonloader_mock.hpp"

namespace study
{

//! \brief  Mocks a lesson.
//!
//! Allows for easy testing of things that depend on lessons.
class LessonMock :
	public Lesson
{
  public:
	LessonMock() :
		Lesson(new LessonLoaderMock) {}

	//! \brief Submit a string as the final answer to the question.
	//!
	//! \param[in] answer is the answer given to the question.
	Lesson& submit(std::string const& answer)
	{
		answer_given_ = answer;
		return *this;
	}

	//! \brief View the latest submition.
	std::string const& view_submition() const
	{
		return answer_given_;
	}

  private:
	std::string answer_given_;
};

} // namespace study

#endif // INCLUDE_TEST_LESSON_MOCK_HPP
