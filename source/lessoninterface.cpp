#include "study/lessoninterface.hpp"
#include <iostream>
#include "study/lesson.hpp"
#include "study/enumutils.hpp"

namespace study
{

LessonInterface::LessonInterface(
	Lesson* loader,
	InStream& ins,
	LogStream& logs,
	OutStream& outs
) :
	state_(LessonInterface::State::noinput),
	lesson_(loader),
	in_(&ins),
	log_(&logs),
	out_(&outs),
	current_exercise_(exercise_list_.begin())
{
	out_->set_interface(*this);
	lesson_->set_interface(*this);
	lesson_->construct();
	lesson_->welcome();
	if (*this) {
		lesson_->start_exercise();
		in_->set_input(lesson_->exercise_input());
	} else {
		lesson_->part();
	}
}

LessonInterface::~LessonInterface()
{
	try {
		lesson_->destruct();
	}
	catch (...) {
		std::cerr << "Exception thrown in LessonInterface::~LessonInterface.  "
			<< "Please report this.\n";
		assert(0);
	}
}

LessonInterface::operator bool() const
{
	return lesson_->exercise_is_valid();
}

bool LessonInterface::operator!() const
{
	return lesson_->exercise_is_valid();
}

LessonInterface& LessonInterface::submit(std::string const& answer)
{
	assert(this);
	current_exercise_->submit(answer);
	lesson_->end_exercise();
	if (*this) {
		lesson_->start_exercise();
		in_->set_input(lesson_->exercise_input());
	} else {
		lesson_->part();
	}
	return *this;
}

void LessonInterface::add_exercise_here(Exercise* e)
{
	ExerciseIterator t = current_exercise_;
	++t;
	exercise_list_.insert(t, e);
}

void LessonInterface::add_exercise_at_end(Exercise* e)
{
	exercise_list_.push_back(e);
}


} // namespace study

