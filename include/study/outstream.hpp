#ifndef INCLUDE_STUDY_OUTSTREAM_HPP
#define INCLUDE_STUDY_OUTSTREAM_HPP

#include <sstream>
#include <string>
#include <boost/utility.hpp>
#include "study/endline.hpp"

namespace study
{

class LessonInterface;

//! \brief  Stream that allows user to submit data.
//! 
//! This provides a replacement for std::ostream that pipes data from the user
//! both to the associated LessonInterface object and the standard output.
class OutStream :
	boost::noncopyable
{
  public:
	OutStream();

	// Custom functions
	//! \brief Reset stream to be empty.
	OutStream& reset();

	//! \brief Return the currently present input.
	std::string retrieve() const;

	//! \brief Set the OutStream to be used.
	OutStream& claim();

	//! \brief Set the OutStream to be not-used.
	OutStream& release();

	//! \brief Return true if the OutStream is set as used.
	bool claimed() const;

	// Standard formatted output
	//! \brief Insert something into the stream.
	//!
	//! Do not overload this:  overload operator<< for std::ostream instead.
	template<typename T>
	OutStream& operator<<(T const& value);
	//! \brief Overload to handle endlines (and, therefore, flushes).
	//!
	//! Simply adds a newline to the end of the input.
	OutStream& operator<<(EndLine const& value);
	
	// Standard unformatted output
	//! \brief Wraps std::ostream::put(char).
	OutStream& put(char ch);
	//! \brief Wraps std::ostream::write(char const*, size_t).
	OutStream& write(char const* s, size_t count);

	// Misc standard
	//! \brief No effect.
	OutStream& flush();

  private:
	bool used_;
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

