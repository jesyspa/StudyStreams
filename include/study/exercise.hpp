#ifndef INCLUDE_STUDY_EXERCISE_HPP
#define INCLUDE_STUDY_EXERCISE_HPP

#include <string>
#include <vector>
#include "study/abstractexercise.hpp"
#include "study/stringutils.hpp"

namespace study
{

//! \brief Represents an exercise in a lesson.
//!
//! This class provides an implementation of AbstractExercise that is suitable
//! for most use-cases.  
class Exercise :
	public AbstractExercise
{
  public:
	//! \brief Prototype for comparison function.
	typedef bool (*compare_func)(std::string const&, std::string const&);

	//! \brief Create an exercise.
	Exercise(
		std::string const& name,
		compare_func compare = simple_compare
	);

	//! \brief Set the name of the exercise.
	//!
	//! The name is used as the first argeter to the exercise (executable name).
	//!
	//! \warning Calling this function in Lesson::get_exercise_args after
	//! get_args() is called is NOT safe.
	virtual Exercise& set_name(std::string const& name);
	//! \brief Set the answer to the exercise.
	virtual Exercise& set_answer(std::string const& answer);
	//! \brief Set the expected return code of the exercise.
	virtual Exercise& set_ret_code(int code);
	//! \brief Set the input passed by the exercise.
	virtual Exercise& set_input(std::string const& input);
	//! \brief Set the compare func to use with the exercise.
	virtual Exercise& set_compare(compare_func compare);
	//! \brief Add another argument.
	//!
	//! \warning Calling this function in Lesson::get_exercise_args after
	//! get_args() is called is NOT safe.
	virtual Exercise& add_arg(std::string const& arg);

	//! \brief Get the name of the exercise.
	virtual std::string get_name() const;
	//! \brief Get the answer to the exercise.
	virtual std::string get_answer() const;
	//! \brief Get the expected return code of the exercise.
	virtual int get_ret_code() const;
	//! \brief Get the input passed by the exercise.
	virtual std::string get_input() const;
	//! \brief Set the compare func to use with the exercise.
	virtual compare_func get_compare() const;
	//! \brief Return all arguments of the exercise.
	//!
	//! It is advised to call this at the last moment, as modifying any of the
	//! arguments after this has been called invokes undefined behaviour.
	virtual std::vector<char*> get_args() const;
	
	//! \brief Append a string to the input.
	//!
	//! Whitespace is inserted between the old and new input.
	virtual Exercise& append_input(std::string const& input);
	
  private:
	std::string name_;
	std::string answer_;
	int ret_code_;
	std::string input_;
	std::vector<std::string> args_;
	compare_func compare_;
	std::string user_answer_;
};

} // namespace study

#endif // INCLUDE_STUDY_EXERCISE_HPP
