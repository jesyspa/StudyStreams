#ifndef INCLUDE_STUDY_EXERCISE_HPP
#define INCLUDE_STUDY_EXERCISE_HPP

#include <string>
#include <boost/parameter/keyword.hpp>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>
#include "study/stringutils.hpp"

namespace study
{
namespace parameter = boost::parameter;

namespace keywords
{

BOOST_PARAMETER_NAME(name)
BOOST_PARAMETER_NAME(answer)
BOOST_PARAMETER_NAME(input)
BOOST_PARAMETER_NAME(pre_desc)
BOOST_PARAMETER_NAME(post_desc)
BOOST_PARAMETER_NAME(compare)

} // namespace keywords

struct Exercise_Impl
{
	typedef bool (*compare_func)(std::string const&, std::string const&);

	enum class State {
		empty = 0, //!< Intended for comparison.
		complete = 1 << 0, //!< Set when input has been provided.
		success = 1 << 1, //!< Set when correct input has been provided.
		fail = 1 << 2, //!< Set when incorrect input has been provided.
		error = 1 << 3, //!< Set when there has been an internal error.
		noinput = 1 << 4 //!< Set until input is provided.
	};

	template<typename ArgumentPack>
	Exercise_Impl(ArgumentPack const& args) :
		state_(State::noinput),
		name_(args[keywords::_name]),
		answer_(args[keywords::_answer | ""]),
		input_(args[keywords::_input | ""]),
		compare_(args[keywords::_compare | simple_compare])
	{
	}

	State state_;
	std::string name_;
	std::string answer_;
	std::string input_;
	compare_func compare_;
  protected:
	Exercise_Impl() {} // Works according to the testcase.  http://ideone.com/i0Far
};

//! \brief Declare and define a parameter-based constructor.
//!
//! Make sure to virtually and privately inherit Exercise_Impl, and
//! publically inherit Exercise.
//! \param[in]ExerciseTypeName is the name of your Exercise subclass.
#define STUDY_EXERCISETYPE_CONSTRUCTOR(ExerciseTypeName) \
	BOOST_PARAMETER_CONSTRUCTOR( \
		ExerciseTypeName, \
		(::study::Exercise_Impl), \
		::study::keywords::tag, \
		(required (name, *)) \
		(optional \
			(answer, *) \
			(input, *) \
			(compare, *) \
		) \
	)

//! \brief Represents an exercise in a lesson.
class Exercise :
	virtual Exercise_Impl
{
  public:
	using Exercise_Impl::State;
	using Exercise_Impl::state_;
	using Exercise_Impl::name_;
	using Exercise_Impl::input_;
	using Exercise_Impl::compare_;
	//! \brief Prototype for comparison function.
	typedef bool (*compare_func)(std::string const&, std::string const&);
	//! \brief Gives the state of the Exercise

	//! \brief Create an exercise.
	//!
	//! \param[in] name is the name of the exercise.
	//! \param[in] pre_desc is the description given before the exercise.
	//! \param[in] post_desc is the description given after the exercise.
	//! \param[in] input is the input the exercise is to give the user.
	//! \param[in] answer is the reply from the user that would be correct.
	//! \param[in] compare is the function to use to compare the expected and
	//!            given answer.
	STUDY_EXERCISETYPE_CONSTRUCTOR(Exercise) // No ; !
  protected:
	Exercise() {} // Necessary for subclasses with parameter constructors to work.
  public:
	virtual ~Exercise() {}

	//! \brief Set the name of the exercise.
	virtual Exercise& set_name(std::string const& name);
	//! \brief Set the answer to the exercise.
	virtual Exercise& set_answer(std::string const& answer);
	//! \brief Set the input passed by the exercise.
	virtual Exercise& set_input(std::string const& input);
	//! \brief Dummy function, used to make code more readable.
	virtual Exercise& and_() { return *this; }

	//! \brief Get the name of the exercise.
	virtual std::string const& get_name() const;
	//! \brief Get the answer to the exercise.
	virtual std::string get_answer() const;
	//! \brief Get the input passed by the exercise.
	virtual std::string get_input() const;
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
	std::string user_answer_;
};

} // namespace study

#endif // INCLUDE_STUDY_EXERCISE_HPP
