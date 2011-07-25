#include "study/instream.hpp"
#include <cassert>
#include "study/lesson.hpp"

namespace study
{

InStream::InStream() {}
InStream::~InStream() {}

InStream& InStream::set_input(std::string const& input)
{
	assert(this);
	iss_.str(input);
	return *this;
}

int InStream::get()
{
	assert(this);
	return iss_.get();
}

int InStream::peek()
{
	assert(this);
	return iss_.peek();
}

InStream& InStream::unget()
{
	assert(this);
	iss_.unget();
	return *this;
}

InStream& InStream::putback(char ch)
{
	assert(this);
	iss_.putback(ch);
	return *this;
}

InStream& InStream::ignore(size_t count)
{
	assert(this);
	iss_.ignore(count);
	return *this;
}

InStream& InStream::ignore(size_t count, char delim)
{
	assert(this);
	iss_.ignore(count, delim);
	return *this;
}

InStream& InStream::read(char* s, size_t count)
{
	assert(this);
	iss_.read(s, count);
	return *this;
}

size_t InStream::gcount() const
{
	assert(this);
	return iss_.gcount();
}

InStream::operator bool() const
{
	return iss_;
}

bool InStream::operator!() const
{
	return !iss_;
}

} // namespace study

