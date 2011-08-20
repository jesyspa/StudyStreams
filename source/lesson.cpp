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
}

void Lesson::start_exercise()
{
}

void Lesson::end_exercise(int retval, std::string const& answer)
{
	assert(this);
	auto& e = get_exercise();
	// Ensure that the answer and return value are as-expected.
	if ((e.get_compare()(answer, e.get_answer())) && (retval == e.get_ret_code())) {
		log() << "Exercise " << e.get_name() << ": passed." << study::endl;
	} else { 
		log() << "Exercise " << e.get_name() << ": failed." << study::endl;
		std::string old_prefix = log().get_prefix();
		log().set_prefix(old_prefix + "==| ");
		log() << "Expected \"" << e.get_answer() << "\"\n"
		      << "Received \"" << answer << "\"" << study::endl;
		log().set_prefix(old_prefix);
	}
	log() << study::endl;
}

void Lesson::part()
{
}

std::string Lesson::get_exercise_input() 
{
	assert(exercise_is_valid());
	return get_exercise().get_input();
}

std::vector<char*> Lesson::get_exercise_args()
{
	assert(exercise_is_valid());
	return get_exercise().get_args();
}

} // namespace study
