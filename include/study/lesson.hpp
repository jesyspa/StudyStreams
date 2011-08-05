#ifndef INCLUDE_STUDY_LESSON_HPP
#define INCLUDE_STUDY_LESSON_HPP

#include "study/exercise.hpp"

namespace study
{

class LessonInterface;
class LogStream;
class OutStream;
class InStream;

//! \brief Abstract base class for loading the lesson.
//!
//! Responsible for creating and storing the exercises and providing the
//! user with information on what is going on.
class Lesson
{
  public:
	virtual ~Lesson() {}

	//! \brief Associate a lesson with this Lesson.
	//!
	//! Should only be called once, although no checks are done.
	void set_interface(LessonInterface& l);

	//! \brief Called when the lesson is first constructed.
	virtual void construct() = 0;

	//! \brief Jump to the first exercise.
	virtual void jump_to_first() = 0;

	//! \brief Called just before the first exercise starts.
	virtual void welcome();

	//! \brief Called at the beginning of every exercise.
	virtual void start_exercise();

	//! \brief Called at the end of every exercise.
	//!
	//! \param[in] answer is the answer the user gave.
	virtual void end_exercise(std::string const& answer);

	//! \brief Move on to the next exercise.
	virtual void next_exercise() = 0;

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
	//! \brief Return a reference to the current exercise.
	virtual Exercise& get_exercise() = 0;

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
