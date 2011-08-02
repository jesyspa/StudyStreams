#ifndef INCLUDE_STUDY_LESSON_HPP
#define INCLUDE_STUDY_LESSON_HPP

#include <boost/ptr_container/ptr_list.hpp>
#include "study/exercise.hpp"

namespace study
{

class LessonInterface;
class LogStream;
class OutStream;
class InStream;

//! \brief Abstract base class for loading the lesson.
//!
//! The name is somewhat misleading:  other than providing the lesson with
//! exercises, it also provides some helper functions for input and output,
//! and for controlling the flow of the lesson.
class Lesson
{
	//! \brief Iterator for Exercises in the LessonInterface.
	typedef boost::ptr_list<Exercise>::iterator ExerciseIterator;
  public:
	virtual ~Lesson() {}

	//! \brief Associate a lesson with this Lesson.
	//!
	//! Should only be called once, although no checks are done.
	void set_interface(LessonInterface& l);

	//! \brief Called when the lesson is first constructed.
	virtual void construct() = 0;

	//! \brief Called just before the first exercise starts.
	virtual void welcome();

	//! \brief Called at the beginning of every exercise.
	virtual void start_exercise();

	//! \brief Called at the end of every exercise.
	virtual void end_exercise();

	//! \brief Called after the last exercise (after end_exercise()).
	virtual void part();

	//! \brief Called just before the object is destructed.
	virtual void destruct();

	//! \brief Return true if the current exercise is valid/present.
	//!
	//! Intended to check whether we are at the last exercise or not.
	virtual bool exercise_is_valid() = 0;

	//! \brief Get the input of the current exercise.
	virtual std::string get_exercise_input() = 0;

  protected:
	//! \brief Return the InStream the lesson is connected to.
	InStream& in();
	
	//! \brief Return the LogStream the lesson is connected to.
	LogStream& log();

	//! \brief Return the OutStream the lesson is connected to.
	OutStream& out();

  private:
	LessonInterface* interface_;
};


} // namespace study

#endif // INCLUDE_STUDY_LESSON_HPP
