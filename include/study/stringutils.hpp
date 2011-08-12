#ifndef INCLUDE_STUDY_STRINGUTILS_HPP
#define INCLUDE_STUDY_STRINGUTILS_HPP

#include <string>

namespace study
{

//! \brief Format a string to fit on a certain screen width and have a prefix.
//!
//! \param[in] input is the string to be parsed.
//! \param[in] prefix is the prefix to prepend to each line.
//! \param[in] max_width is the maximum length of a line.
//! \return Returns a string that contains the inputted, formatted.
std::string string_format(
	std::string const& input,
	std::string const& prefix,
	unsigned int max_width
);

//! \brief Replaces special characters with their escape codes.
//!
//! \param[in] in is the string to be sanitised.
//! \return Return a copy of the string.
std::string string_sanitise(std::string const& in);

//! \brief Literal comparison.
//!
//! \param[in] answer is the answer expected.
//! \param[in] actual is the answer given.
//! \return Return true if strings are judged to be equal.
bool simple_compare(
	std::string const& answer,
	std::string const& actual
);

//! \brief Literal comparison.
//!
//! \param[in] answer is the answer expected.
//! \param[in] actual is the answer given.
//! \return Return true if strings are judged to be equal.
bool loose_compare(
	std::string const& answer,
	std::string const& actual
);

//! \brief Comparison that ignores whitespace.
//!
//! \warning Not implemented.
//!
//! \param[in] answer is the answer expected.
//! \param[in] actual is the answer given.
//! \return Return true if strings are judged to be equal.
bool whitespace_ignore_compare(
	std::string const& answer,
	std::string const& actual
);

//! \brief Comparison that treats the two strings as streams of floats.
//!
//! As always with float comparisons, things may not work as expected, and
//! there has been no testing with generated values.  Please report any unexpected
//! results!
//! 
//! \param[in] answer is the answer expected.
//! \param[in] actual is the answer given.
//! \return Return true if strings are judged to be equal.
bool float_compare(
	std::string const& answer,
	std::string const& actual
);

} // namespace study

#endif // INCLUDE_STUDY_STRINGUTILS_HPP
