#ifndef INCLUDE_STUDY_LESSONINTERFACE_HPP
#define INCLUDE_STUDY_LESSONINTERFACE_HPP

#include <string>
#include <boost/utility.hpp>
#include <boost/scoped_ptr.hpp>
#include "study/exercise.hpp"
#include "study/io.hpp"
#include "study/lesson.hpp"

namespace study
{

class Lesson;

//! \brief  Represents a lesson.
//!
//! Each program written by a student should have a LessonInterface object that feeds
//! data through study::cin and monitors the output through study::cout.  
//!
//! Virtual for mocking reasons.
class LessonInterface
{
	//! \brief Iterator for Exercises in the LessonInterface.
	friend class Lesson;
  public:
	//! \brief Initialise the LessonInterface.
	//!
	//! \param[in] loader is the loader to use.  The lesson takes ownership of it.
	//! \param[in,out] ins is the stream to be used for getting input from
	//!                the lesson.
	//! \param[in,out] logs is the stream to be used for displaying output from
	//!                the lesson.
	//! \param[in,out] outs is the stream to be used for passing output to
	//!                the lesson.
	LessonInterface(
		Lesson* lesson,
		InStream& ins = study::cin,
		LogStream& logs = study::lout,
		OutStream& outs = study::cout
	);
	~LessonInterface();
	
	//! \brief Return true if there are more exercises.
	operator bool() const;
	
	//! \brief Return true if there are no more exercises.
	bool operator!() const;

	//! \brief Submit a string as the final answer to the question.
	//!
	//! Do not use externally -- OutStreams are designed to hide this.
	//!
	//! \param[in] answer is the answer given to the question.
	LessonInterface& submit(std::string const& answer);

  private:
	boost::scoped_ptr<Lesson> lesson_;
	InStream* in_;
	LogStream* log_;
	OutStream* out_;
};

} // namespace study

#endif // INCLUDE_STUDY_LESSONINTERFACE_HPP

