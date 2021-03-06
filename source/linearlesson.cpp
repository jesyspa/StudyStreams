#include "study/linearlesson.hpp"
#include "study/lesson.hpp"
#include "study/exercise.hpp"
#include "study/lessoninterface.hpp"
#include "study/instream.hpp"
#include "study/logstream.hpp"
#include "study/outstream.hpp"

namespace study
{

void LinearLesson::next_exercise()
{
	++current_exercise_;
}

bool LinearLesson::exercise_is_valid()
{
	return current_exercise_ != exercise_list_.end();
}

AbstractExercise& LinearLesson::get_exercise()
{
	return *current_exercise_;
}

void LinearLesson::jump_to_first()
{
	current_exercise_ = exercise_list_.begin();
}

void LinearLesson::add_exercise(AbstractExercise* e)
{
	exercise_list_.push_back(e);
}

	
} // namespace study
