#ifndef INCLUDE_STUDY_PLACEHOLDER_HPP
#define INCLUDE_STUDY_PLACEHOLDER_HPP

#include <string>

namespace study
{

//! \brief  Return a placeholder value.
//! 
//! This function should be used to indicate to a user what areas to replace
//! with his own constants.  Returns the default-constructed value for most
//! types, but specialised for the more common cases.
template<typename R>
inline R replace_with_a_()
{
	return R();
}

template<>
inline char replace_with_a_<char>()
{
	return '?';
}

template<>
inline int replace_with_a_<int>()
{
	return 314159;
}

template<>
inline std::string replace_with_a_<std::string>()
{
	return "<Placeholder std::string>";
}

template<>
inline char const* replace_with_a_<char const*>()
{
	return "<Placeholder const char*>";
}

template<>
inline double replace_with_a_<double>()
{
	return 3.14159;
}

//! \brief Wraps replace_with_a_.
//!
//! Intended merely for aesthetic value.
template<typename R>
inline R replace_with_an_()
{
	return replace_with_a_<R>();
}

} // namespace study

#endif // INCLUDE_STUDY_PLACEHOLDER_HPP

