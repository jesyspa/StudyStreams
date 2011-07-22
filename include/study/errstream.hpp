#ifndef INCLUDE_STUDY_ERRSTREAM_HPP
#define INCLUDE_STUDY_ERRSTREAM_HPP

#include "study/outstream.hpp"

namespace study {

//! \brief  Stream that allows user to output to the screen.
//! 
//! This provides a replacement for std::ostream that pipes data from the user
//! to only the standard output.  It is a specialisation of OutStream with no
//! lesson attached.
class ErrStream :
	OutStream
{
  public:
	ErrStream();

	// Standard formatted output
	OutStream& operator<<(bool value);
	OutStream& operator<<(char value);
	OutStream& operator<<(int value);
	OutStream& operator<<(unsigned int value);
	OutStream& operator<<(float value);
	OutStream& operator<<(double value);
	OutStream& operator<<(char* value);
	OutStream& operator<<(std::string value);
	OutStream& operator<<(void* value);

	// Standard unformatted output
	OutStream& put(char ch);
	OutStream& write(char const* s, size_t count);
};

} // namespace study
#endif // INCLUDE_STUDY_ERRSTREAM_HPP
