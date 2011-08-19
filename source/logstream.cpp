#include "study/logstream.hpp"
#include <cassert>
#include <list>
#include <iterator>
#include <boost/tokenizer.hpp>
#include "study/stringutils.hpp"

namespace study
{

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

LogStream& LogStream::disconnect_from_ostream()
{
	assert(this);
	os_ = 0;
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
	this->flush();
	return *this;
}

LogStream& LogStream::put(char ch)
{
	assert(this);
	oss_.put(ch);
	return *this;
}

LogStream& LogStream::write(char const* s, size_t count)
{
	assert(this);
	oss_.write(s, count);
	return *this;
}

LogStream& LogStream::flush() {
	assert(this);
	assert(os_);
	(*os_) << format_(oss_.str(), prefix_, screen_width_);
	oss_.str("");
	return *this;
}

} // namespace study

