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
	OutStream(Lesson& lesson);
	~OutStream();

	// Custom functions
	//! \brief Associate the stream with a certain lesson.
	OutStream& set_lesson(Lesson& lesson);

	//! \brief Return true if stream is associated with a lesson.
	bool has_lesson() const;

	// Standard formatted output
	//! \brief Insert something into the stream.
	//!
	//! Do not overload this:  overload operator<< for std::ostream instead.
	template<typename T>
	OutStream& operator<<(T const& value);
	//! \brief Overload to handle endlines (and, therefore, flushes).
	OutStream& operator<<(EndLine const& value);
	
	// Standard unformatted output
	//! \brief Wraps std::ostream::put(char).
	OutStream& put(char ch);
	//! \brief Wraps std::ostream::write(char const*, size_t).
	OutStream& write(char const* s, size_t count);

	// Misc standard
	//! \brief Submit the answer.  Same as operator<<(Endline const&).
	OutStream& flush();

  private:
	Lesson* lesson_;
	std::ostringstream oss_;
};

template<typename T>
inline OutStream& OutStream::operator<<(T const& value)
{
	oss_ << value;
	return *this;
}

} // namespace study

#endif // INCLUDE_STUDY_OUTSTREAM_HPP

