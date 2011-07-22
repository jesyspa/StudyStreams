#include "study/instream.hpp"
#include "study/lesson.hpp"

namespace study
{

InStream::InStream() {}
InStream::~InStream() {}

int InStream::get()
{
	return 150493;
}

int InStream::peek()
{
	return 150493;
}

InStream& InStream::unget()
{
	return *this;
}

InStream& InStream::putback(char ch)
{
	return *this;
}

InStream& InStream::ignore(size_t count)
{
	return *this;
}

InStream& InStream::ignore(size_t count, char delim)
{
	return *this;
}

InStream& InStream::read(char* s, size_t count)
{
	return *this;
}

size_t InStream::gcount() const
{
	return 150493;
}

} // namespace study

