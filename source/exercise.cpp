#include "study/exercise.hpp"
#include <cassert>
#include <string>
#include <boost/foreach.hpp>
#include "study/enumutils.hpp"

namespace study
{

Exercise::Exercise(std::string const& name, compare_func compare) :
	name_(name),
	ret_code_(0),
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

Exercise& Exercise::set_ret_code(int ret_code)
{
	ret_code_ = ret_code;
	return *this;
}

Exercise& Exercise::set_input(std::string const& input)
{
	input_ = input;
	return *this;
}

Exercise& Exercise::add_arg(std::string const& arg)
{
	args_.push_back(arg);
	return *this;
}

Exercise& Exercise::set_compare(compare_func compare)
{
	compare_ = compare;
	return *this;
}

std::string Exercise::get_name() const
{
	return name_;
}

std::string Exercise::get_answer() const
{
	return answer_;
}

int Exercise::get_ret_code() const
{
	return ret_code_;
}

std::string Exercise::get_input() const
{
	return input_;
}

std::vector<char*> Exercise::get_args() const
{
	// The following code makes use of const_cast.  Not very elegant, but
	// std::string::data() is not required to return a null-terminated array, while
	// std::string::c_str() is.  Seeing as main takes a char*[], there's no choice
	// but to cast it in an ugly way like this.
	//
	// The documentation should mention somewhere that modifying argv is idiotic
	// and not acceptable.
	std::vector<char*> args_raw_;
	args_raw_.push_back(const_cast<char*>(name_.c_str()));
	BOOST_FOREACH(std::string s, args_)
	{
		args_raw_.push_back(const_cast<char*>(s.c_str()));
	}
	return args_raw_;
}

Exercise::compare_func Exercise::get_compare() const
{
	return compare_;
}

Exercise& Exercise::append_input(std::string const& input)
{
	assert(this);
	input_ += ' ' + input;
	return *this;
}


} // namespace study

