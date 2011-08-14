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

	enum class State {
		empty = 0, //!< Intended for comparison.
		complete = 1 << 0, //!< Set when input has been provided.
		success = 1 << 1, //!< Set when correct input has been provided.
		fail = 1 << 2, //!< Set when incorrect input has been provided.
		error = 1 << 3, //!< Set when there has been an internal error.
		noinput = 1 << 4 //!< Set until input is provided.
	};
	//! \brief Gives the state of the AbstractExercise

	//! \brief Create an exercise.
	AbstractExercise(
		std::string const& name,
		compare_func compare = simple_compare
	);
  public:
	virtual ~AbstractExercise() {}

	//! \brief Set the name of the exercise.
	virtual AbstractExercise& set_name(std::string const& name) = 0;
	//! \brief Set the answer to the exercise.
	virtual AbstractExercise& set_answer(std::string const& answer) = 0;
	//! \brief Set the input passed by the exercise.
	virtual AbstractExercise& set_input(std::string const& input) = 0;
	//! \brief Set the compare func to use with the exercise.
	virtual AbstractExercise& set_compare(compare_func compare) = 0;
	//! \brief Add another argument.
	virtual AbstractExercise& add_arg(std::string const& arg) = 0;
	//! \brief Dummy function, used to make code more readable.
	AbstractExercise& and_() { return *this; }

	//! \brief Get the name of the exercise.
	virtual std::string const& get_name() const = 0;
	//! \brief Get the answer to the exercise.
	virtual std::string get_answer() = 0;
	//! \brief Get the input passed by the exercise.
	virtual std::string get_input() = 0;
	//! \brief Set the compare func to use with the exercise.
	virtual compare_func get_compare();
	//! \brief Return all arguments of the exercise.
	virtual std::vector<char*> get_args() = 0;
	//! \brief Get the actual answer recieved.
	virtual std::string const& get_user_answer() = 0;
	
	//! \brief Reset the exercise, removing the answer given.
	//!
	//! Should not clear error flags.
	AbstractExercise& reset() = 0;

	//! \brief Append a string to the input.
	//!
	//! Whitespace is inserted between the old and new input.
	virtual AbstractExercise& append_input(std::string const& input) = 0;
	
	//! \brief Submit the answer.
	virtual AbstractExercise& submit(std::string const& user_answer) = 0;

	//! \brief Check whether the result has a certain flag set.
	//!
	//! If flags are ORed, checked that all are set.  Other flags may be set,
	//! too, use result_is_exactly if you don't want this.
	//!
	//! \arg[in] st is the state to be checked for.
	bool result_is(AbstractExercise::State st) const;

	//! \brief Check whether the result has any of the ORed flags set.
	//!
	//! Assuming ORed flags, check whether at least one is set.
	//!
	//! \arg[in] st is the state to be checked for.
	bool result_is_some_of(AbstractExercise::State st) const;

	//! \brief Check whether the result has exactly some flags set.
	//!
	//! Assuming ORed flags, check whether only these flags are set.
	bool result_is_exactly(AbstractExercise::State st) const;

  protected:
	//! \brief Mark all bits in st as set.
	void set_result(AbstractExercise::State st);
	
	//! \brief Mark all bits in st as unset.
	void unset_result(AbstractExercise::State st);

  private:
	State state_;
};

} // namespace study

#endif // INCLUDE_STUDY_ABSTRACTEXERCISE_HPP

