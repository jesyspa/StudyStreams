#include <cassert>
#include "study/outstream.hpp"
#include "study/lessoninterface.hpp"

namespace study
{

OutStream::OutStream() :
	used_(false)
{
}

OutStream& OutStream::reset()
{
	assert(this);
	oss_.str("");
	oss_.clear();
	return *this;
}

std::string OutStream::retrieve() const
{
	assert(this);
	return oss_.str();
}

OutStream& OutStream::claim()
{
	assert(this);
	used_ = true;
	return *this;
}

OutStream& OutStream::release()
{
	assert(this);
	used_ = false;
	return *this;
}

bool OutStream::claimed() const
{
	assert(this);
	return used_;
}

OutStream& OutStream::operator<<(EndLine const& /*value*/)
{
	assert(this);
	*this << '\n';
	flush();
	return *this;
}

OutStream& OutStream::put(char ch)
{
	assert(this);
	oss_.put(ch);
	return *this;
}

OutStream& OutStream::write(char const* s, size_t count)
{
	assert(this);
	oss_.write(s, count);
	return *this;
}

// Currently does absolutely nothing.
OutStream& OutStream::flush()
{
	assert(this);
	return *this;
}

} // namespace study

