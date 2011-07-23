#include "study/logstream.hpp"
#include <cassert>
#include <list>
#include <iterator>
#include <boost/tokenizer.hpp>

namespace study
{

namespace {

std::string string_format(
	std::string const& input,
	std::string const& prefix,
	unsigned int max_width)
{
	boost::char_separator<char> sep("\n");
	boost::tokenizer<boost::char_separator<char>> tok(input, sep);
	std::list<std::string> res;
	std::string out;
	for (auto it = tok.begin(); it != tok.end(); ++it)
		res.push_back(*it);
	for (auto it = res.begin(); it != res.end(); ++it) {
		*it = prefix + *it;
		// Will need some length-handling code here.
		out += *it + '\n';
	}
	return out;
}

} // namespace 

LogStream::LogStream() :
	os_(0),
	screen_width_(80),
	prefix_("| "),
	format_(&string_format)
{
}

LogStream::LogStream(std::ostream& os) :
	os_(&os),
	screen_width_(80),
	prefix_("| "),
	format_(&string_format)
{
}

LogStream::~LogStream()
{
}

LogStream& LogStream::connect_to_ostream(std::ostream& os)
{
	assert(this);
	os_ = &os;
	return *this;
}

bool LogStream::has_ostream() const
{
	assert(this);
	return os_;
}

LogStream& LogStream::set_screen_width(unsigned int width)
{
	assert(this);
	screen_width_ = width;
	return *this;
}

unsigned int LogStream::get_screen_width() const
{
	assert(this);
	return screen_width_;
}

LogStream& LogStream::set_prefix(std::string const& prefix)
{
	assert(this);
	prefix_ = prefix;
	return *this;
}

std::string const& LogStream::get_prefix() const
{
	assert(this);
	return prefix_;
}

LogStream& LogStream::operator<<(EndLine const& /*value*/)
{
	assert(this);
	oss_ << '\n';
	(*os_) << format_(oss_.str(), prefix_, screen_width_);
	return *this;
}
} // namespace study

