#include "study/outstream.hpp"
#include "study/lesson.hpp"

namespace study
{

OutStream::OutStream() {}
OutStream::~OutStream() {}

void OutStream::set_lesson(Lesson& lesson) {}

bool OutStream::has_lesson() const
{
	return true;
}

Lesson& OutStream::get_lesson()
{
	return *this->lesson_;
}

template<typename T>
OutStream& OutStream::operator<<(T const& value)
{
	return *this;
}

template<>
OutStream& OutStream::operator<<<EndLine>(EndLine const& value)
{
	return *this;
}

OutStream& OutStream::put(char ch)
{
	return *this;
}

OutStream& OutStream::write(char const* s, size_t count)
{
	return *this;
}

OutStream& OutStream::flush()
{
	return *this;
}

} // namespace study

