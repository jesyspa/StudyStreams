#include "study/lesson.hpp"

namespace study
{

Lesson::Lesson(
	std::string const& title,
	InStream& ins,
	LogStream& logs,
	OutStream& outs)
{
}

Lesson::State Lesson::result() const
{
	return State::error | State::noinput;
}

} // namespace study

