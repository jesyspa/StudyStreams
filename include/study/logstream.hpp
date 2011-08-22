#ifndef INCLUDE_STUDY_LOGSTREAM_HPP
#define INCLUDE_STUDY_LOGSTREAM_HPP

#include "study/endline.hpp"
#include <boost/utility.hpp>
#include <functional>
#include <ostream>
#include <sstream>
#include <string>

namespace study
{

class LessonInterface;

//! \brief  Stream that allows user to submit data.
//! 
//! This provides a replacement for std::ostream that pipes data from the user
//! both to the associated LessonInterface object and the standard output.
class LogStream :
	boost::noncopyable
{
	typedef std::function<
		std::string (
			std::string const& // String to format
		)
	> string_format_func;
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

	//! \brief Disconnects from the ostream currently connected to.
	//!
	//! No effect if not connected.
	LogStream& disconnect_from_ostream();

	//! \brief Return true if connected to an ostream.
	bool has_ostream() const;

	//! \brief Set the format function to be used.
	LogStream& set_format_func(string_format_func const& func);

	//! \brief Return the format function currently used.
	string_format_func const& get_format_func() const;

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

