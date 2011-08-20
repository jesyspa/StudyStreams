#ifndef INCLUDE_STUDY_SOLUTION_HPP
#define INCLUDE_STUDY_SOLUTION_HPP

namespace study
{

class LessonInterface;
class InStream;
class LogStream;
class OutStream;

//! \brief Derived class for giving less power to solutions.
//!
//! In case when a student should not be given private access to the lesson,
//! the solution may be encapsulated in this class, which still provides the
//! useful portion of the public interface, but does not allow things like
//! jumping to the first exercise or getting the exercise and then the expected
//! input and output.
class Solution
{
  public:
	//! \brief Bind the Solution to a lesson.
	Solution(LessonInterface& lesson);

	//! \brief Make sure the class can be used polymorphically.
	//!
	//! Should not be required, as derived classes are not expected to implement
	//! destructors, but kept for safety.
	virtual ~Solution() {} 

	//! \brief Return the associated InStream.
	InStream& in();

	//! \brief Return the associated LogStream.
	LogStream& log();

	//! \brief Return the associated OutStream.
	OutStream& out();

	//! \brief Should be overriden with the student's program.
	virtual int solution(int argc, char* argv[]) = 0;

  private:
	LessonInterface* lesson_;
};

}

#endif // INCLUDE_STUDY_SOLUTION_HPP

