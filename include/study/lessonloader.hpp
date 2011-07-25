#ifndef INCLUDE_STUDY_LESSONLOADER_HPP
#define INCLUDE_STUDY_LESSONLOADER_HPP

#include <boost/ptr_container/ptr_list.hpp>
#include "study/exercise.hpp"

namespace study
{

class Lesson;
class LogStream;
class OutStream;
class InStream;

//! \brief Abstract base class for loading the lesson.
//!
//! The name is somewhat misleading:  other than providing the lesson with
//! exercises, it also provides some helper functions for input and output,
//! and for controlling the flow of the lesson.
class LessonLoader
{
	//! \brief Iterator for Exercises in the Lesson.
	typedef boost::ptr_list<Exercise>::iterator ExerciseIterator;
  public:
	virtual ~LessonLoader() {}

	//! \brief Associate a lesson with this LessonLoader.
	//!
	//! Should only be called once, although no checks are done.
	void set_lesson(Lesson& l);

	//! \brief Called when the lesson is first constructed.
	virtual void construct() = 0;

	//! \brief Called just before the first exercise starts.
	virtual void welcome() {}

	//! \brief Called at the end of every exercise.
	virtual void end_exercise() {}

	//! \brief Called after the last exercise (after end_exercise()).
	virtual void part() {}

	//! \brief Called just before the object is destructed.
	virtual void destruct() {}

  protected:
	//! \brief Return the InStream the lesson is connected to.
	InStream& in();
	
	//! \brief Return the LogStream the lesson is connected to.
	LogStream& log();

	//! \brief Return the OutStream the lesson is connected to.
	OutStream& out();

	//! \brief Return the the lesson is connected to.
	Lesson& lesson();

	//! \brief Return an iterator to the first exercise.
	ExerciseIterator first_exercise();

	//! \brief Return an iterator to the one-past-last exercise.
	ExerciseIterator last_exercise();

	//! \brief Return an iterator to the current exercise.
	ExerciseIterator current_exercise();

	//! \brief Add an exercise after the current one.
	void add_exercise_here(Exercise* e);

	//! \brief Add an exercise to the end of the lesson.
	void add_exercise_at_end(Exercise* e);

  private:
	Lesson* lesson_;
};


} // namespace study

#endif // INCLUDE_STUDY_LESSONLOADER_HPP
