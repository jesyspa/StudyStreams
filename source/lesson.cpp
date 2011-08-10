#include "study/lesson.hpp"
#include "study/exercise.hpp"
#include "study/lessoninterface.hpp"
#include "study/instream.hpp"
#include "study/logstream.hpp"
#include "study/outstream.hpp"

namespace study
{

void Lesson::set_interface(LessonInterface& l)
{
	assert(this);
	interface_ = &l;
}

InStream& Lesson::in()
{
	assert(this);
	return interface_->in();
}

LogStream& Lesson::log()
{
	assert(this);
	return interface_->log();
}

OutStream& Lesson::out()
{
	assert(this);
	return interface_->out();
}

void Lesson::welcome()
{
	assert(this);
	log() << "------ Start Lesson ------\n" << study::endl;
}

void Lesson::start_exercise()
{
	assert(this);
}

void Lesson::end_exercise(std::string const& answer)
{
	assert(this);
	Exercise& e = get_exercise();
	e.submit(answer);
	if (e.result_is(Exercise::State::success)) {
		log() << "Exercise " << e.get_name() << ": passed." << study::endl;
	} else { // Assuming exercises always succeed or fail.
		log() << "Exercise " << e.get_name() << ": failed." << study::endl;
		std::string old_prefix = log().get_prefix();
		log().set_prefix(old_prefix + "==| ");
		log() << "Expected \"" << e.get_answer() << "\"\n"
		      << "Received \"" << e.get_user_answer() << "\"" << study::endl;
		log().set_prefix(old_prefix);
	}
	log() << study::endl;
}

void Lesson::part()
{
	assert(this);
	log() << "\n------  End Lesson ------" << study::endl;
}

void Lesson::destruct()
{
	assert(this);
}

} // namespace study
