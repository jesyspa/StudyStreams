#ifndef INCLUDE_STUDY_LESSON_HPP
#define INCLUDE_STUDY_LESSON_HPP

#include <string>
#include <boost/utility.hpp>
#include "study/io.hpp"

namespace study
{

//! \brief  Represents a lesson.
//!
//! Each program written by a student should have a Lesson object that feeds
//! data through study::cin and monitors the output through study::cout.  
class Lesson
{
  public:
	Lesson(std::string const&, InStream& = study::cin, OutStream& = study::cout);

	int result() const;

  private:
	OutStream* out;
	InStream* in;
};

} // namespace study

#endif // INCLUDE_STUDY_OUTSTREAM_HPP
