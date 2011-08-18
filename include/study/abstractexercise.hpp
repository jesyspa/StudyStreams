#ifndef INCLUDE_STUDY_ABSTRACTEXERCISE_HPP
#define INCLUDE_STUDY_ABSTRACTEXERCISE_HPP

#include <string>
#include <vector>
#include "study/stringutils.hpp"

namespace study
{

//! \brief Abstract base class for exercises.
class AbstractExercise
{
  public:
	//! \brief Prototype for comparison function.
	typedef bool (*compare_func)(std::string const&, std::string const&);

	virtual ~AbstractExercise() {}

	//! \brief Set the name of the exercise.
	virtual AbstractExercise& set_name(std::string const& name) = 0;
	//! \brief Set the answer to the exercise.
	virtual AbstractExercise& set_answer(std::string const& answer) = 0;
	//! \brief Set the expected return code of the exercise.
	virtual AbstractExercise& set_ret_code(int code) = 0;
	//! \brief Set the input passed by the exercise.
	virtual AbstractExercise& set_input(std::string const& input) = 0;
	//! \brief Set the compare func to use with the exercise.
	virtual AbstractExercise& set_compare(compare_func compare) = 0;
	//! \brief Add another argument.
	virtual AbstractExercise& add_arg(std::string const& arg) = 0;

	//! \brief Get the name of the exercise.
	virtual std::string get_name() const = 0;
	//! \brief Get the answer to the exercise.
	virtual std::string get_answer() const = 0;
	//! \brief Get the expected return code of the exercise.
	virtual int get_ret_code() const = 0;
	//! \brief Get the input passed by the exercise.
	virtual std::string get_input() const = 0;
	//! \brief Set the compare func to use with the exercise.
	virtual compare_func get_compare() const = 0;
	//! \brief Return all arguments of the exercise.
	virtual std::vector<char*> get_args() const = 0;
	
	//! \brief Append a string to the input.
	//!
	//! Whitespace is inserted between the old and new input.
	virtual AbstractExercise& append_input(std::string const& input) = 0;
};

} // namespace study

#endif // INCLUDE_STUDY_ABSTRACTEXERCISE_HPP

