#ifndef INCLUDE_STUDY_EXERCISE_HPP
#define INCLUDE_STUDY_EXERCISE_HPP

#include <string>
#include "study/stringutils.hpp"

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
	//! \brief Prototype for comparison function.
	typedef bool (*compare_func)(std::string const&, std::string const&);
	//! \brief Gives the state of the Exercise
	enum class State {
		empty = 0, //!< Intended for comparison.
		complete = 1 << 0, //!< Set when input has been provided.
		success = 1 << 1, //!< Set when correct input has been provided.
		fail = 1 << 2, //!< Set when incorrect input has been provided.
		error = 1 << 3, //!< Set when there has been an internal error.
		noinput = 1 << 4 //!< Set until input is provided.
	};

	//! \brief Create an exercise.
	//!
	//! \param[in] name is the name of the exercise.
	//! \param[in] pre_description is the description given before the exercise.
	//! \param[in] post_description is the description given after the exercise.
	//! \param[in] input is the input the exercise is to give the user.
	//! \param[in] answer is the reply from the user that would be correct.
	//! \param[in] compare is the function to use to compare the expected and
	//!            given answer.
	Exercise(
		std::string const& name = "",
		std::string const& answer = "",
		std::string const& input = "",
		std::string const& pre_description = "",
		std::string const& post_description = "",
		compare_func compare = simple_compare
	);
	virtual ~Exercise() {}

	//! \brief Set the name of the exercise.
	Exercise& set_name(std::string const& name);
	//! \brief Set the answer to the exercise.
	Exercise& set_answer(std::string const& answer);
	//! \brief Set the input passed by the exercise.
	Exercise& set_input(std::string const& input);
	//! \brief Set the description at the beginning of the exercise.
	Exercise& set_pre_description(std::string const& pre_description);
	//! \brief Set the description at the end of the exercise.
	Exercise& set_post_description(std::string const& post_description);
	//! \brief Dummy function, used to make code more readable.
	Exercise& and_() { return *this; }

	//! \brief Get the name of the exercise.
	std::string const& get_name() const;
	//! \brief Get the answer to the exercise.
	std::string const& get_answer() const;
	//! \brief Get the input passed by the exercise.
	std::string const& get_input() const;
	//! \brief Get the description at the beginning of the exercise.
	std::string const& get_pre_description() const;
	//! \brief Get the description at the end of the exercise.
	std::string const& get_post_description() const;
	//! \brief Get the actual answer recieved.
	std::string const& get_received() const;
	
	//! \brief Reset the exercise, removing the answer given.
	//!
	//! Does not clear error flags.
	virtual Exercise& reset();

	//! \brief Submit the answer.
	virtual Exercise& submit(std::string const& given_answer);

	//! \brief Check whether the result has a certain flag set.
	//!
	//! If flags are ORed, checked that all are set.  Other flags may be set,
	//! too, use result_is_exactly if you don't want this.
	//!
	//! \param[in] st is the state to be checked for.
	bool result_is(Exercise::State st) const;

	//! \brief Check whether the result has any of the ORed flags set.
	//!
	//! Assuming ORed flags, check whether at least one is set.
	//!
	//! \param[in] st is the state to be checked for.
	bool result_is_some_of(Exercise::State st) const;

	//! \brief Check whether the result has exactly some flags set.
	//!
	//! Assuming ORed flags, check whether only these flags are set.
	bool result_is_exactly(Exercise::State st) const;

  private:
	State state_;
	std::string name_;
	std::string answer_;
	std::string input_;
	std::string pre_description_;
	std::string post_description_;
	std::string received_answer_;
	compare_func compare_;
};

} // namespace study

#endif // INCLUDE_STUDY_EXERCISE_HPP
