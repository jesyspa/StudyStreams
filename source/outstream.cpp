#include <cassert>
#include "study/outstream.hpp"
#include "study/lesson.hpp"

namespace study
{

OutStream::OutStream() :
	lesson_(0)
{
}

OutStream::OutStream(Lesson& lesson) :
	lesson_(&lesson)
{
}

OutStream::~OutStream() {}

OutStream& OutStream::set_lesson(Lesson& lesson)
{
	assert(this);
	lesson_ = &lesson;
	return *this;
}

bool OutStream::has_lesson() const
{
	assert(this);
	return lesson_;
}

OutStream& OutStream::operator<<(EndLine const& /*value*/)
{
	assert(this);
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

OutStream& OutStream::flush()
{
	assert(this);
	assert(lesson_);
	lesson_->submit(oss_.str());
	oss_.str("");
	oss_.clear();
	return *this;
}

} // namespace study

