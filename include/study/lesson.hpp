#ifndef INCLUDE_STUDY_LESSON_HPP
#define INCLUDE_STUDY_LESSON_HPP

#include <vector>
#include <boost/utility.hpp>
#include "study/abstractexercise.hpp"

namespace study
{

class LessonInterface;
class LogStream;
class OutStream;
class InStream;

//! \brief Abstract base class for loading the lesson.
//!
//! This class provides the interface LessonInterface uses in order to
//! run the lesson.  The lesson being implemented should derive from this
//! class.
//!
//! LessonInterface takes ownership of the Lesson* it is passed, so it is
//! advised to only create instances of any derived classes with new.
//!
//! Note that in most cases, LinearLesson is sufficient.
class Lesson :
	boost::noncopyable
{
  public:
	//! \brief Constructor.  May throw.
	//!
	//! This function should create all the exercises, and do any other set-up
	//! that is required.
	//!
	//! Please document what exercises your constructor will create.
	//! 
	//! There is no need to set the first exercise as the current, as 
	//! jump_to_first() is guaranteed to be called before any exercises are
	//! run.
	//!
	//! \warning The LessonInterface object will _NOT_ be available from here.
	//!          Any input/output should be done in the welcome() function.
	Lesson();

	//! \brief Destructor.  Should not throw.
	//!
	//! This should clean up any resources claimed by the constructor.
	virtual ~Lesson() {}

	//! \brief Associate a lesson with this Lesson.
	//!
	//! Should only be called once, although no checks are done.
	void set_interface(LessonInterface& l);

	//! \brief Jump to the first exercise.
	//!
	//! This function will be called before any exercises are run.
	//!
	//! The logic behind splitting the constructor  and jump_to_first() is to allow
	//! generic Lesson classes like LinearLesson, which do not themselves
	//! construct any exercises, but are store them.  In that case, the final
	//! class will probably want to override construct(), but not jump_to_first().
	virtual void jump_to_first() = 0;

	//! \brief Called just before the first exercise starts.
	//!
	//! This function may display some greeting text.  The default implementation
	//! will do nothing.
	virtual void welcome();

	//! \brief Called at the beginning of every exercise.
	//!
	//! This function should display any text you wish to see before every exercise.
	//! The default implementation will not do anything.
	virtual void start_exercise();

	//! \brief Called at the end of every exercise.
	//!
	//! \param[in] retval is the return value of the user's program.
	//! \param[in] answer is the answer the user gave.
	virtual void end_exercise(int retval, std::string const& answer);

	//! \brief Move on to the next exercise.
	virtual void next_exercise() = 0;

	//! \brief Called after the last exercise (after end_exercise()).
	//!
	//! This function may display some parting text.  The default implementation
	//! will do nothing.
	virtual void part();

	//! \brief Return true if the current exercise is valid/present.
	//!
	//! Intended to check whether we are at the last exercise or not.  It is
	//! assumed that when this is returns false, the lesson should end.  If this
	//! is undesired, try to repair the error here, or throw.
	virtual bool exercise_is_valid() = 0;

	//! \brief Handle an exception thrown by the solution.
	//!
	//! This function is called whenever the solution throws an exception that
	//! derives from std::exception.
	//!
	//! \param[in] e is the exception that was thrown
	virtual void handle_exception(std::exception& e);

	//! \brief Get the input of the current exercise.
	std::string get_exercise_input();

	//! \brief Return the arguments that are to be passed to the exercise.
	//!
	//! Note the copy.  While this could be a performance issue, it should be
	//! okay, seeing as only the char* get copied, not the strings themselves.
	//! Also, this allows the vectors to be generated directly in this
	//! function.
	std::vector<char*> get_exercise_args();

	//! \brief Function to be written by student.
	//!
	//! In some cases, it may be more convenient to use this as a wrapper.  See the
	//! Solution class for details on how this is best done.
	virtual int solution(int argc, char* argv[]) = 0;

	//! \brief Return the InStream the lesson is connected to.
	InStream& in();
	
	//! \brief Return the LogStream the lesson is connected to.
	LogStream& log();

	//! \brief Return the OutStream the lesson is connected to.
	OutStream& out();

  protected:
	//! \brief Return a reference to the current exercise.
	virtual AbstractExercise& get_exercise() = 0;

  private:
	LessonInterface* interface_;
};

} // namespace study

#endif // INCLUDE_STUDY_LESSON_HPP
