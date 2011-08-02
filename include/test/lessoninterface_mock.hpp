#ifndef INCLUDE_TEST_LESSONINTERFACE_MOCK_HPP
#define INCLUDE_TEST_LESSONINTERFACE_MOCK_HPP

#include <cassert>
#include <string>
#include <boost/utility.hpp>
#include "study/io.hpp"
#include "study/lessoninterface.hpp"
#include "study/lesson.hpp"
#include "test/lesson_mock.hpp"

namespace study
{

//! \brief  Mocks a lesson interface.
//!
//! Allows for easy testing of things that depend on lesson interfaces.
class LessonInterfaceMock :
	public LessonInterface
{
  public:
	LessonInterfaceMock() :
		LessonInterface(new LessonMock) {}

	//! \brief Submit a string as the final answer to the question.
	//!
	//! \param[in] answer is the answer given to the question.
	LessonInterface& submit(std::string const& answer)
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

#endif // INCLUDE_TEST_LESSONINTERFACE_MOCK_HPP
