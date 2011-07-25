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

std::string string_normalise(std::string const& in);

//! \brief Literal comparison.
//!
//! \param[in] answer is the answer expected.
//! \param[in] actual is the answer given.
//! \return Return true if strings are judged to be equal.
bool simple_compare(
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

} // namespace study

#endif // INCLUDE_STUDY_STRINGUTILS_HPP
