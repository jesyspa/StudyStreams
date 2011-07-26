#ifndef INCLUDE_STUDY_LESSON_HPP
#define INCLUDE_STUDY_LESSON_HPP

#include <string>
#include <boost/utility.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include <boost/scoped_ptr.hpp>
#include "study/exercise.hpp"
#include "study/io.hpp"

namespace study
{

class LessonLoader;

//! \brief  Represents a lesson.
//!
//! Each program written by a student should have a Lesson object that feeds
//! data through study::cin and monitors the output through study::cout.  
//!
//! Virtual for mocking reasons.
class Lesson
{
	//! \brief Iterator for Exercises in the Lesson.
	typedef boost::ptr_list<Exercise>::iterator ExerciseIterator;
	friend class LessonLoader;
  public:
	//! \brief Enumeration of possible lesson states.
	enum class State {
		empty = 0, //!< Intended for comparison.
		complete = 1 << 0, //!< Set when all exercises are complete.
		success = 1 << 1, //!< Set when all complete exercises are successful.
		fail = 1 << 2, //!< Set when there is at least one failed exercise.
		error = 1 << 3, //!< Set when there is an internal error (if possible).
		noinput = 1 << 4 //!< Set until there is some input from the user.
	};
	
	//! \brief Initialise the Lesson.
	//!
	//! \param[in] loader is the loader to use.  The lesson takes ownership of it.
	//! \param[in,out] ins is the stream to be used for getting input from
	//!                the lesson.
	//! \param[in,out] logs is the stream to be used for displaying output from
	//!                the lesson.
	//! \param[in,out] outs is the stream to be used for passing output to
	//!                the lesson.
	Lesson(
		LessonLoader* loader,
		InStream& ins = study::cin,
		LogStream& logs = study::lout,
		OutStream& outs = study::cout
	);
	virtual ~Lesson();
	
	//! \brief Return true if there are more exercises.
	operator bool() const;
	
	//! \brief Return true if there are no more exercises.
	bool operator!() const;

	//! \brief Return the result of the lesson so far.
	Lesson::State result() const;

	//! \brief Check whether the result has a certain flag set.
	//!
	//! If flags are ORed, checked that all are set.  Other flags may be set,
	//! too, use result_is_exactly if you don't want this.
	//!
	//! \warning Not implemented.
	//!
	//! \param[in] st is the state to be checked for.
	bool result_is(Lesson::State st) const;

	//! \brief Check whether the result has any of the ORed flags set.
	//!
	//! Assuming ORed flags, check whether at least one is set.
	//!
	//! \warning Not implemented.
	//!
	//! \param[in] st is the state to be checked for.
	bool result_is_one_of(Lesson::State st) const;

	//! \brief Check whether the result has exactly some flags set.
	//!
	//! \warning Not implemented.
	//!
	//! Assuming ORed flags, check whether only these flags are set.
	bool result_is_exactly(Lesson::State st) const;

	//! \brief Submit a string as the final answer to the question.
	//!
	//! Do not use externally -- OutStreams are designed to hide this.
	//!
	//! \param[in] answer is the answer given to the question.
	virtual Lesson& submit(std::string const& answer);

	//! \brief Go to the first exercise.
	//!
	//! \warning Not implemented.
	void go_to_first();

	//! \brief Go to the previous exercise.
	//!
	//! \warning Not implemented.
	void go_to_previous();

	//! \brief Restart the current exercise.
	//!
	//! \warning Not implemented.
	void restart_exercise();

	//! \brief Go to the next exercise.
	//!
	//! \warning Not implemented.
	void go_to_next();

	//! \brief End this lesson.
	//!
	//! \warning Not implemented.
	//!
	//! Current exercise counts as skipped.
	void end_lesson();

	//! \brief Display progress on the current exercise.
	//!
	//! \warning Not implemented.
	void display_progress_current();

	//! \brief Display progress on all exercises.
	//!
	//! \warning Not implemented.
	void display_progress_all();

  private:
	//! \brief Add an exercise after the current one.
	void add_exercise_here(Exercise* e);

	//! \brief Add an exercise to the end of the lesson.
	void add_exercise_at_end(Exercise* e);

	State state_;
	LessonLoader* lesson_loader_;
	InStream* in_;
	LogStream* log_;
	OutStream* out_;
	boost::ptr_list<Exercise> exercise_list_;
	ExerciseIterator current_exercise_;
};

} // namespace study

#endif // INCLUDE_STUDY_LESSON_HPP

