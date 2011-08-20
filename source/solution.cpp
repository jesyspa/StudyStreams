#include "study/solution.hpp"
#include "study/lessoninterface.hpp"
#include "study/instream.hpp"
#include "study/logstream.hpp"
#include "study/outstream.hpp"

namespace study
{

Solution::Solution(LessonInterface& lesson) :
	lesson_(&lesson)
{}

InStream& Solution::in()
{
	assert(lesson_);
	return lesson_->in();
}

LogStream& Solution::log()
{
	assert(lesson_);
	return lesson_->log();
}

OutStream& Solution::out()
{
	assert(lesson_);
	return lesson_->out();
}

} // namespace study
