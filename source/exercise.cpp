#include "study/exercise.hpp"
#include <cassert>
#include <string>
#include "study/enumutils.hpp"

namespace study
{

Exercise::Exercise(compare_func compare) :
	state_(State::noinput),
	compare_(compare)
{}

Exercise& Exercise::set_name(std::string const& name)
{
	name_ = name;
	return *this;
}

Exercise& Exercise::set_answer(std::string const& answer)
{
	answer_ = answer;
	return *this;
}

Exercise& Exercise::set_input(std::string const& input)
{
	input_ = input;
	return *this;
}

Exercise& Exercise::set_compare(compare_func compare)
{
	compare_ = compare;
	return *this;
}

std::string const& Exercise::get_name() const
{
	return name_;
}

std::string Exercise::get_answer() const
{
	return answer_;
}

std::string Exercise::get_input() const
{
	return input_;
}

Exercise::compare_func Exercise::get_compare()
{
	return compare_;
}

std::string const& Exercise::get_user_answer() const
{
	return user_answer_;
}


Exercise& Exercise::reset()
{
	assert(this);
	state_ &= State::error;
	state_ |= State::noinput;
	return *this;
}

Exercise& Exercise::append_input(std::string const& input)
{
	assert(this);
	input_ += ' ' + input;
	return *this;
}

Exercise& Exercise::submit(std::string const& user_answer)
{
	assert(this);
	user_answer_ = user_answer;
	if (compare_(user_answer, answer_))
		state_ |= (State::success | State::complete);
	else
		state_ |= (State::fail | State::complete);
	state_ &= ~State::noinput;
	return *this;
}

bool Exercise::result_is(Exercise::State st) const
{
	assert(this);
	return state_has_all(state_, st);
}

bool Exercise::result_is_some_of(Exercise::State st) const
{
	assert(this);
	return state_has_some(state_, st);
}

bool Exercise::result_is_exactly(Exercise::State st) const
{
	assert(this);
	return state_has_all(state_, st) && state_has_only(state_, st);
}

void Exercise::set_result(Exercise::State st)
{
	assert(this);
	state_ = set(state_, st);
}

void Exercise::unset_result(Exercise::State st)
{
	assert(this);
	state_ = unset(state_, st);
}

} // namespace study

