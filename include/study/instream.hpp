#ifndef INCLUDE_STUDY_INSTREAM_HPP
#define INCLUDE_STUDY_INSTREAM_HPP

#include <sstream>
#include <string>
#include <boost/utility.hpp>
#include "study/endline.hpp"

namespace study
{

//! \brief  Stream that accepts input for the user.
//! 
//! This provides a replacement for std::istream that pipes the lesson
//! assignments directly into the student's program.
class InStream :
	boost::noncopyable
{
  public:
	InStream();
	~InStream();

	// Standard formatted input
	template<typename T>
	InStream& operator>>(T& value);

	// Standard unformatted input
	int get();
	int peek();
	InStream& unget();
	InStream& putback(char ch);
	InStream& ignore(size_t count = 1);
	InStream& ignore(size_t count, char delim);
	InStream& read(char* s, size_t count);
	size_t gcount() const;
};

template<typename T>
inline InStream& InStream::operator>>(T& value)
{
	return *this;
}

} // namespace study

#endif // INCLUDE_STUDY_INSTREAM_HPP

