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
	std::string const& pre_desc,
	std::string const& post_desc,
	compare_func compare
) :
	state_(State::noinput),
	name_(name),
	answer_(answer),
	input_(input),
	pre_desc_(pre_desc),
	post_desc_(post_desc),
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

Exercise& Exercise::set_pre_desc(std::string const& pre_desc)
{
	assert(this);
	pre_desc_ = pre_desc;
	return *this;
}

Exercise& Exercise::set_post_desc(std::string const& post_desc)
{
	assert(this);
	post_desc_ = post_desc;
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

std::string const& Exercise::get_pre_desc() const
{
	assert(this);
	return pre_desc_;
}

std::string const& Exercise::get_post_desc() const
{
	assert(this);
	return post_desc_;
}

std::string const& Exercise::get_user_answer() const
{
	assert(this);
	return user_answer_;
}


Exercise& Exercise::reset()
{
	assert(this);
	state_ &= State::error;
	state_ |= State::noinput;
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


} // namespace study

