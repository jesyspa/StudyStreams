#ifndef INCLUDE_STUDY_LINEARLESSON_HPP
#define INCLUDE_STUDY_LINEARLESSON_HPP

#include "study/lesson.hpp"
#include <boost/ptr_container/ptr_list.hpp>
#include <vector>

namespace study
{

//! \brief Somewhat less abstract class for linear lessons.
//!
//! This class is suitable in most cases where lessons follow a strict
//! order.
class LinearLesson :
	public Lesson
{
  public:
	//! \brief Jump to the first exercise.
	virtual void jump_to_first();

	//! \brief Move on to the next exercise.
	//!
	//! Overriding is not advised.  At least call this one if you do.
	virtual void next_exercise();

	//! \brief Return true if the current exercise is valid/present.
	//!
	//! Intended to check whether we are at the last exercise or not.
	virtual bool exercise_is_valid();

  protected:
	//! \brief Return a reference to the current exercise.
	virtual AbstractExercise& get_exercise();

	//! \brief Add an exercise to the list that have to be done.
	//!
	//! Exercises will be done in the order added.
	void add_exercise(AbstractExercise* e);

  private:
	boost::ptr_list<AbstractExercise> exercise_list_;
	boost::ptr_list<AbstractExercise>::iterator current_exercise_;
};


} // namespace study

#endif // INCLUDE_STUDY_LINEARLESSON_HPP
