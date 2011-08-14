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
	out_->claim();
	lesson_->set_interface(*this);
	lesson_->construct();
}

LessonInterface::~LessonInterface()
{
	assert(lesson_);
	try
	{
		lesson_->destruct();
		out().release();
	}
	catch (...)
	{
		std::cerr << "Exception thrown in LessonInterface::~LessonInterface.  "
			<< "Please report this.\n";
		assert(0);
	}
}

void LessonInterface::run()
{
	// - Check that all necessary pointers are set.
	// - Make sure the lesson is at its beginning.
	// - Greet the user
	// - Run all exercises (greeting, running, checking, parting, moving on)
	// - Say good-bye to the user
	assert(this);
	assert(lesson_);
	lesson_->jump_to_first();
	lesson_->welcome(); // Global greeting text
	while (lesson_->exercise_is_valid())
	{
		lesson_->start_exercise(); // Per-exercise greeting text
		in().set_input(lesson_->get_exercise_input());
		auto args = lesson_->get_exercise_args();
		int ret = lesson_->solution(args.size(), args.data()); // Actual work
		lesson_->end_exercise(ret, out().retrieve()); // Per-exercise parting text
		out().reset();
		lesson_->next_exercise();
	} 
	lesson_->part(); // Parting text
}

InStream& LessonInterface::in()
{
	assert(this);
	assert(in_);
	return *in_;
}

OutStream& LessonInterface::out()
{
	assert(this);
	assert(out_);
	return *out_;
}

LogStream& LessonInterface::log()
{
	assert(this);
	assert(log_);
	return *log_;
}

} // namespace study

