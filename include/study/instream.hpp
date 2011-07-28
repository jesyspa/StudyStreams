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
	InStream(std::string const& input);
	~InStream();

	//! \brief Set the string that will be passed to the user.
	//!
	//! Do not use internally -- this is for the lesson to use.
	//!
	//! \param[in] input is the data that will be passed to the user.
	InStream& set_input(std::string const& input);

	// Standard formatted input
	//! \brief Extract a value from the stream.
	template<typename T>
	InStream& operator>>(T& value);

	// Standard unformatted input
	//! \brief Wraps std::istream::get().
	int get();
	//! \brief Wraps std::istream::peek().
	int peek();
	//! \brief Wraps std::istream::unget().
	InStream& unget();
	//! \brief Wraps std::istream::putback().
	InStream& putback(char ch);
	//! \brief Wraps std::istream::ignore(size_t).
	InStream& ignore(size_t count = 1);
	//! \brief Wraps std::istream::ignore(size_t, char).
	InStream& ignore(size_t count, char delim);
	//! \brief Wraps std::istream::read(char*, size_t).
	InStream& read(char* s, size_t count);
	//! \brief Wraps std::istream::gcount().
	size_t gcount() const;

	// Checking for validity
	//! \brief Return true if stream is good.
	operator bool() const;
	//! \brief Return true if stream is not good.
	bool operator!() const;
  private:
	std::istringstream iss_;
};

template<typename T>
inline InStream& InStream::operator>>(T& value)
{
	iss_ >> value;
	return *this;
}

} // namespace study

#endif // INCLUDE_STUDY_INSTREAM_HPP

