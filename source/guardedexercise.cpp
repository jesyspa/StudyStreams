#include "study/guardedexercise.hpp"

namespace study
{

std::string GuardedExercise::get_input() const
{
	return Exercise::get_input() + " GUARD\n TEXT\n"; // To prevent stream from dying.
}

} // namespace study

