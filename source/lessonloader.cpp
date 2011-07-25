#include "study/lessonloader.hpp"
#include "study/lesson.hpp"
#include "study/instream.hpp"
#include "study/logstream.hpp"
#include "study/outstream.hpp"

namespace study
{

void LessonLoader::set_lesson(Lesson& l)
{
	lesson_ = &l;
}

InStream& LessonLoader::in()
{
	return *lesson_->in_;
}

LogStream& LessonLoader::log()
{
	return *lesson_->log_;
}

OutStream& LessonLoader::out()
{
	return *lesson_->out_;
}

Lesson& LessonLoader::lesson()
{
	return *lesson_;
}

LessonLoader::ExerciseIterator LessonLoader::first_exercise()
{
	return lesson_->exercise_list_.begin();
}

LessonLoader::ExerciseIterator LessonLoader::last_exercise()
{
	return lesson_->exercise_list_.end();
}

LessonLoader::ExerciseIterator LessonLoader::current_exercise()
{
	return lesson_->current_exercise_;
}

void LessonLoader::add_exercise_here(Exercise* e)
{
	lesson_->add_exercise_here(e);
}

void LessonLoader::add_exercise_at_end(Exercise* e)
{
	lesson_->add_exercise_at_end(e);
}

} // namespace study
