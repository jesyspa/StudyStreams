#ifndef INCLUDE_STUDY_EXERCISE_HPP
#define INCLUDE_STUDY_EXERCISE_HPP

#include "study/abstractexercise.hpp"
#include "study/stringutils.hpp"
#include <functional>
#include <string>
#include <vector>

namespace study
{

//! \brief Represents an exercise in a lesson.
//!
//! This class provides an implementation of AbstractExercise that is suitable
//! for most use-cases.  It is intended as a way of bundling everything related
//! to a single exercise so that the lesson knows how to conduct it, and the 
//!
//! In general, it is safe to assume that all instances of Exercise should be
//! created with new.  This is not currently enforced, but due to LinearLesson
//! taking ownership of the Exercises, your lesson will probably crash if you
//! have any exercises that are not newed.
//!
//! The standard syntax for creating an exercise is:
//!
//! Exercise* = &(new Exercise("Name", function))->
//!         set_input("5 6 7 8").
//!         set_answer("8 7 6 5").
//!         set_ret_code(0).
//!         add_arg("4")
//!
//! Any number of set_ and add_ functions may be chained this way.  The order
//! that the args are added in is the order in which they will be passed on the
//! command line.
class Exercise :
	public AbstractExercise
{
  public:
	//! \brief Prototype for comparison function.
	typedef std::function<
		bool (
			std::string const&,
			std::string const&
		)
	> compare_func;

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
	Exercise& set_name(std::string const& name);
	//! \brief Set the answer to the exercise.
	Exercise& set_answer(std::string const& answer);
	//! \brief Set the expected return code of the exercise.
	Exercise& set_ret_code(int code);
	//! \brief Set the input passed by the exercise.
	Exercise& set_input(std::string const& input);
	//! \brief Set the compare func to use with the exercise.
	Exercise& set_compare(compare_func compare);
	//! \brief Add another argument.
	//!
	//! \warning Calling this function in Lesson::get_exercise_args after
	//! get_args() is called is NOT safe.
	Exercise& add_arg(std::string const& arg);

	//! \brief Get the name of the exercise.
	std::string get_name() const;
	//! \brief Get the answer to the exercise.
	std::string get_answer() const;
	//! \brief Get the expected return code of the exercise.
	int get_ret_code() const;
	//! \brief Get the input passed by the exercise.
	std::string get_input() const;
	//! \brief Set the compare func to use with the exercise.
	compare_func get_compare() const;
	//! \brief Return all arguments of the exercise.
	//!
	//! It is advised to call this at the last moment, as modifying any of the
	//! arguments after this has been called invokes undefined behaviour.
	std::vector<char*> get_args() const;
	
	//! \brief Append a string to the input.
	//!
	//! Whitespace is inserted between the old and new input.
	Exercise& append_input(std::string const& input);
	
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
