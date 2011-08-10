#ifndef INCLUDE_STUDY_GUARDEDEXERCISE_HPP
#define INCLUDE_STUDY_GUARDEDEXERCISE_HPP

#include <string>
#include <boost/parameter/keyword.hpp>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>
#include "study/exercise.hpp"
#include "study/stringutils.hpp"

namespace study
{
//! \brief Represents an exercise that keeps the stream valid.
//!
//! Unlike study::Exercise, where the stream will become invalid after
//! every exercise, this class will keep it valid.  However, this does
//! mean that the student will have to have some way of not reading too
//! far, or it will seem like the lesson is over too early.
class GuardedExercise :
	virtual Exercise_Impl,
	public Exercise
{
  public:
	//! \brief Create a GuardedExercise.
	//!
	//! See the documentation of the constructor Exercise for details.
	STUDY_EXERCISETYPE_CONSTRUCTOR(GuardedExercise) // No ; !

	//! \brief Get the input passed by the exercise.
	virtual std::string get_input() const;
};

} // namespace study

#endif // INCLUDE_STUDY_GUARDEDEXERCISE_HPP

