#ifndef INCLUDE_STUDY_OUTSTREAM_HPP
#define INCLUDE_STUDY_OUTSTREAM_HPP

#include <sstream>
#include <string>
#include <boost/utility.hpp>
#include "study/endline.hpp"

namespace study
{

class Lesson;

//! \brief  Stream that allows user to submit data.
//! 
//! This provides a replacement for std::ostream that pipes data from the user
//! both to the associated Lesson object and the standard output.
class OutStream :
	boost::noncopyable
{
  public:
	OutStream();
	~OutStream();

	// Custom functions
	//! \brief Associate the stream with a certain lesson.
	void set_lesson(Lesson& lesson);

	//! \brief Return true if stream is associated with a lesson.
	bool has_lesson() const;

	//! \brief Return a reference to the lesson.
	//!
	//! If there is no lesson associated, the behaviour of this function is
	//! undefined.
	Lesson& get_lesson();

	// Standard formatted output
	template<typename T>
	OutStream& operator<<(T const& value);
	
	// Standard unformatted output
	OutStream& put(char ch);
	OutStream& write(char const* s, size_t count);

	// Misc standard
	OutStream& flush();

  private:
	Lesson* lesson_;
};

} // namespace study

#endif // INCLUDE_STUDY_OUTSTREAM_HPP

