#ifndef INCLUDE_STUDY_EXERCISE_HPP
#define INCLUDE_STUDY_EXERCISE_HPP

#include <string>
#include "study/stringutils.hpp"

namespace study
{

//! \brief Represents an exercise in a lesson.
class Exercise
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
	//! \brief Gives the state of the Exercise

	//! \brief Create an exercise.
	Exercise(compare_func compare = simple_compare);
  public:
	virtual ~Exercise() {}

	//! \brief Set the name of the exercise.
	virtual Exercise& set_name(std::string const& name);
	//! \brief Set the answer to the exercise.
	virtual Exercise& set_answer(std::string const& answer);
	//! \brief Set the input passed by the exercise.
	virtual Exercise& set_input(std::string const& input);
	//! \brief Set the compare func to use with the exercise.
	virtual Exercise& set_compare(compare_func compare);
	//! \brief Dummy function, used to make code more readable.
	virtual Exercise& and_() { return *this; }

	//! \brief Get the name of the exercise.
	virtual std::string const& get_name() const;
	//! \brief Get the answer to the exercise.
	virtual std::string get_answer() const;
	//! \brief Get the input passed by the exercise.
	virtual std::string get_input() const;
	//! \brief Set the compare func to use with the exercise.
	virtual compare_func get_compare();
	//! \brief Get the actual answer recieved.
	virtual std::string const& get_user_answer() const;
	
	//! \brief Reset the exercise, removing the answer given.
	//!
	//! Does not clear error flags.
	Exercise& reset();

	//! \brief Append a string to the input.
	//!
	//! Whitespace is inserted between the old and new input.
	virtual Exercise& append_input(std::string const& input);
	
	//! \brief Submit the answer.
	virtual Exercise& submit(std::string const& user_answer);

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

  protected:
	//! \brief Mark all bits in st as set.
	void set_result(Exercise::State st);
	
	//! \brief Mark all bits in st as unset.
	void unset_result(Exercise::State st);

  private:
	State state_;
	std::string name_;
	std::string answer_;
	std::string input_;
	compare_func compare_;
	std::string user_answer_;
};

} // namespace study

#endif // INCLUDE_STUDY_EXERCISE_HPP
