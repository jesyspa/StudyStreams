#ifndef INCLUDE_STUDY_LOGSTREAM_HPP
#define INCLUDE_STUDY_LOGSTREAM_HPP

#include <ostream>
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
class LogStream :
	boost::noncopyable
{
	typedef std::string (*string_format_func)(
		std::string const&, // String to format
		std::string const&, // Prefix
		unsigned int); // Max line length
  public:
	//! \brief Create a logstream that is not connected to any ostream.
	//!
	//! The LogStream will need to be connected before it is used.
	LogStream();
	
	//! \brief Create a logstream that is connected to the passed ostream.
	//!
	//! \param[in,out] os is the ostream to connect to.
	explicit LogStream(std::ostream& os);

	~LogStream();

	//! \brief Connect to a new ostream.
	//!
	//! The old ostream is disconnected from.
	//!
	//! \param[in,out] os is the ostream to be connected to.
	LogStream& connect_to_ostream(std::ostream& os);

	//! \brief Return true if connected to an ostream.
	bool has_ostream() const;

	//! \brief Set the screen width.
	//!
	//! 0 means endless width.  By default, this is 80.
	//! 
	//! \param[in] width is the new width
	LogStream& set_screen_width(unsigned int width);

	//! \brief Return the screen width.
	//!
	//! Intended for testing.
	unsigned int get_screen_width() const;

	//! \brief Set the log prefix.
	//!
	//! By default, this is "| ".
	//!
	//! \param[in] prefix is the prefix to use.
	LogStream& set_prefix(std::string const& prefix);

	//! \brief Return the log prefix.
	//!
	//! Intended for testing.
	std::string const& get_prefix() const;

	// Standard formatted output
	//! \brief Insert a value into the stream.
	template<typename T>
	LogStream& operator<<(T const& value);
	//! \brief Overload to handle endlines.
	LogStream& operator<<(EndLine const& value);
	
	// Standard unformatted output
	//! \brief Wraps std::ostream::put(char).
	LogStream& put(char ch);
	//! \brief Wraps std::ostream::write(char const*, size_t).
	LogStream& write(char const* s, size_t count);

	// Misc standard
	//! \brief Causes the stream to be flushed.
	//!
	//! A newline is added anyway (to do otherwise makes no sense).
	LogStream& flush();

  private:
	std::ostream* os_;
	std::ostringstream oss_;
	unsigned int screen_width_;
	std::string prefix_;
	string_format_func format_;
};

template<typename T>
LogStream& LogStream::operator<<(T const& value)
{
	oss_ << value;
	return *this;
}


} // namespace study

#endif // INCLUDE_STUDY_LOGSTREAM_HPP

