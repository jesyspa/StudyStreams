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

void LessonLoader::welcome()
{
	log() << "------ Start Lesson ------\n" << study::endl;
}

void LessonLoader::start_exercise()
{
	auto e = current_exercise();
	if (e->get_pre_desc().length())
		log() << e->get_pre_desc() << study::endl;
}

void LessonLoader::end_exercise()
{
	auto e = current_exercise();
	if (e->result_is(Exercise::State::success)) {
		log() << "Exercise " << e->get_name() << ": success." << study::endl;
	} else { // Assuming exercises always succeed or fail.
		log() << "Exercise " << e->get_name() << ": fail." << study::endl;
		std::string old_prefix = log().get_prefix();
		log().set_prefix(old_prefix + "==| ");
		log() << "Expected \"" << e->get_answer() << "\"\n"
		      << "Received \"" << e->get_user_answer() << "\"" << study::endl;
		log().set_prefix(old_prefix);
	}
	if (e->get_post_desc().length())
		log() << e->get_post_desc() << study::endl;
	log() << study::endl;
}

void LessonLoader::part()
{
	log() << "\n------  End Lesson  ------" << study::endl;
}

void LessonLoader::destruct()
{
}

} // namespace study
