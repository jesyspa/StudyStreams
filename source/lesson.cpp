#include "study/lesson.hpp"
#include <iostream>
#include "study/lessonloader.hpp"
#include "study/enumutils.hpp"

namespace study
{

Lesson::Lesson(
	LessonLoader* loader,
	InStream& ins,
	LogStream& logs,
	OutStream& outs
) :
	state_(Lesson::State::noinput),
	lesson_loader_(loader),
	in_(&ins),
	log_(&logs),
	out_(&outs),
	current_exercise_(exercise_list_.begin())
{
	out_->set_lesson(*this);
	lesson_loader_->set_lesson(*this);
	lesson_loader_->construct();
	current_exercise_ = exercise_list_.begin();
	lesson_loader_->welcome();
	if (*this) {
		lesson_loader_->start_exercise();
		in_->set_input(current_exercise_->get_input());
	} else {
		lesson_loader_->part();
	}
}

Lesson::~Lesson()
{
	try {
		lesson_loader_->destruct();
		delete lesson_loader_;
	}
	catch (...) {
		std::cerr << "Exception thrown in Lesson::~Lesson.  Please report this.\n";
		assert(0);
	}
}

Lesson::operator bool() const
{
	return current_exercise_ != exercise_list_.end();
}

bool Lesson::operator!() const
{
	return current_exercise_ == exercise_list_.end();
}

Lesson::State Lesson::result() const
{
	assert(this);
	return state_;
}

bool Lesson::result_is(Lesson::State st) const
{
	assert(this);
	return state_has_all(state_, st);
}

Lesson& Lesson::submit(std::string const& answer)
{
	assert(this);
	current_exercise_->submit(answer);
	lesson_loader_->end_exercise();
	++current_exercise_;
	if (*this) {
		lesson_loader_->start_exercise();
		in_->set_input(current_exercise_->get_input());
	} else {
		lesson_loader_->part();
	}
	return *this;
}

void Lesson::add_exercise_here(Exercise* e)
{
	ExerciseIterator t = current_exercise_;
	++t;
	exercise_list_.insert(t, e);
}

void Lesson::add_exercise_at_end(Exercise* e)
{
	exercise_list_.push_back(e);
}


} // namespace study

