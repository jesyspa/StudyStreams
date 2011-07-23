#ifndef INCLUDE_EXERCISE_LESSON_HPP
#define INCLUDE_EXERCISE_LESSON_HPP

namespace study
{

//! \brief Represents an excercise in a lesson.
//!
//! Only used internally: you should not encounter this class when creating
//! or solving exercises.
//!
//! 
class Exercise
{
  public:
	typedef bool (comparefunc*)(std::string const&, std::string const&);
	//! \brief Gives the state of the Exercise
	enum class State {
		complete = 1 << 0, //!< Set when input has been provided.
		success = 1 << 1, //!< Set when correct input has been provided.
		fail = 1 << 2, //!< Set when incorrect input has been provided.
		error = 1 << 3, //!< Set when there has been an internal error.
		noinput = 1 << 4 //!< Set until input is provided.
	};

	Exercise(
		std::string const& name,
		std::string const& description,
		std::string const& answer,
		
	);
};

} // namespace study

#endif // INCLUDE_EXERCISE_OUTSTREAM_HPP
