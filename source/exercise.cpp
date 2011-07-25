#include "study/exercise.hpp"
#include <cassert>
#include <string>
#include "study/enumutils.hpp"

namespace study
{

Exercise::Exercise(
	std::string const& name,
	std::string const& answer,
	std::string const& input,
	std::string const& pre_description,
	std::string const& post_description,
	compare_func compare
) :
	state_(State::noinput),
	name_(name),
	answer_(answer),
	input_(input),
	pre_description_(pre_description),
	post_description_(post_description),
	compare_(compare)
{
}

Exercise& Exercise::set_name(std::string const& name)
{
	assert(this);
	name_ = name;
	return *this;
}

Exercise& Exercise::set_answer(std::string const& answer)
{
	assert(this);
	answer_ = answer;
	return *this;
}

Exercise& Exercise::set_input(std::string const& input)
{
	assert(this);
	input_ = input;
	return *this;
}

Exercise& Exercise::set_pre_description(std::string const& pre_description)
{
	assert(this);
	pre_description_ = pre_description;
	return *this;
}

Exercise& Exercise::set_post_description(std::string const& post_description)
{
	assert(this);
	post_description_ = post_description;
	return *this;
}

std::string const& Exercise::get_name() const
{
	assert(this);
	return name_;
}

std::string const& Exercise::get_answer() const
{
	assert(this);
	return answer_;
}

std::string const& Exercise::get_input() const
{
	assert(this);
	return input_;
}

std::string const& Exercise::get_pre_description() const
{
	assert(this);
	return pre_description_;
}

std::string const& Exercise::get_post_description() const
{
	assert(this);
	return post_description_;
}

std::string const& Exercise::get_received() const
{
	assert(this);
	return received_answer_;
}


Exercise& Exercise::reset()
{
	assert(this);
	state_ &= State::error;
	state_ |= State::noinput;
	return *this;
}

Exercise& Exercise::submit(std::string const& given_answer)
{
	assert(this);
	received_answer_ = given_answer;
	if (compare_(given_answer, answer_))
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


} // namespace study

