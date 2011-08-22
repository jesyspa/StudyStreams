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
	format_(string_format())
{
}

LogStream::LogStream(std::ostream& os) :
	os_(&os),
	format_(string_format())
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

LogStream& LogStream::set_format_func(string_format_func const& func)
{
	assert(this);
	format_ = func;
	return *this;
}

LogStream::string_format_func const& LogStream::get_format_func() const
{
	assert(this);
	return format_;
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
	assert(format_);
	(*os_) << format_(oss_.str());
	oss_.str("");
	return *this;
}

} // namespace study

