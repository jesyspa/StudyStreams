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
	//! \brief Enumeration of possible lesson states.
	enum class State {
		complete = 1 << 0, //!< Set when all exercises are complete.
		success = 1 << 1, //!< Set when all complete exercises are successful.
		fail = 1 << 2, //!< Set when there is at least one failed exercise.
		error = 1 << 3, //!< Set when there is an internal error (if possible).
		noinput = 1 << 4 //!< Set until there is some input from the user.
			//!< Reset every exercise.
	};
	
	//! \brief Initialise the Lesson.
	//!
	//! \param[in] path is the path to the lesson file
	//! \param[in,out] ins is the stream to be used for getting input from
	//!                the lesson.
	//! \param[in,out] logs is the stream to be used for displaying output from
	//!                the lesson.
	//! \param[in,out] outs is the stream to be used for passing output to
	//!                the lesson.
	Lesson(
		std::string const& path,
		InStream& ins = study::cin,
		LogStream& logs = study::lout,
		OutStream& outs = study::cout
	);
	~Lesson();

	//! \brief Return the result of the lesson so far.
	Lesson::State result() const;

	//! \brief Check whether the result has a certain flag set.
	//!
	//! If flags are ORed, checked that all are set.  Other flags may be set,
	//! too, use result_is_exactly if you don't want this.
	//!
	//! \param[in] st is the state to be checked for.
	bool result_is(Lesson::State st) const;

	//! \brief Check whether the result has any of the ORed flags set.
	//!
	//! Assuming ORed flags, check whether at least one is set.
	//!
	//! \param[in] st is the state to be checked for.
	bool result_is_one_of(Lesson::State st) const;

	//! \brief Check whether the result has exactly some flags set.
	//!
	//! Assuming ORed flags, check whether only these flags are set.
	bool result_is_excatly(Lesson::State st) const;

	//! \brief Go to the first exercise.
	void go_to_first();

	//! \brief Go to the previous exercise.
	void go_to_previous();

	//! \brief Restart the current exercise.
	void restart_exercise();

	//! \brief Go to the next exercise.
	void go_to_next();

	//! \brief End this lesson.
	//!
	//! Current exercise counts as skipped.
	void end_lesson();

	//! \brief Display progress on the current exercise.
	void display_progress_current();

	//! \brief Display progress on all exercises.
	void display_progress_all();

  private:
	OutStream* out;
	InStream* in;
};

} // namespace study

//! \brief Binary OR for Lesson States.
inline study::Lesson::State operator|(
	study::Lesson::State s1,
	study::Lesson::State s2)
{
	return study::Lesson::State(int(s1) | int(s2));
}

//! \brief Binary AND for Lesson States.
inline study::Lesson::State operator&(
	study::Lesson::State s1,
	study::Lesson::State s2)
{
	return study::Lesson::State(int(s1) & int(s2));
}

//! \brief Binary XOR for Lesson States.
inline study::Lesson::State operator^(
	study::Lesson::State s1,
	study::Lesson::State s2)
{
	return study::Lesson::State(int(s1) ^ int(s2));
}

#endif // INCLUDE_STUDY_LESSON_HPP
