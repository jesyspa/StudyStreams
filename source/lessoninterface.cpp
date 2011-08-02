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
	lesson_(loader),
	in_(&ins),
	log_(&logs),
	out_(&outs)
{
	assert(lesson_);
	out_->set_interface(*this);
	lesson_->set_interface(*this);
	lesson_->construct();
	lesson_->jump_to_first();
	lesson_->welcome();
	if (*this) {
		lesson_->start_exercise();
		in_->set_input(lesson_->get_exercise_input());
	} else {
		lesson_->part();
	}
}

LessonInterface::~LessonInterface()
{
	assert(lesson_);
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
	assert(this);
	assert(lesson_);
	return lesson_->exercise_is_valid();
}

bool LessonInterface::operator!() const
{
	assert(this);
	assert(lesson_);
	return !lesson_->exercise_is_valid();
}

LessonInterface& LessonInterface::submit(std::string const& answer)
{
	assert(this);
	assert(lesson_);
	lesson_->end_exercise(answer);
	lesson_->next_exercise();
	if (*this) {
		lesson_->start_exercise();
		in_->set_input(lesson_->get_exercise_input());
	} else {
		lesson_->part();
	}
	return *this;
}

} // namespace study

