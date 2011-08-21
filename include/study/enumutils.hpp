#ifndef INCLUDE_STUDY_ENUMUTILS_HPP
#define INCLUDE_STUDY_ENUMUTILS_HPP

namespace study
{

//! \brief Binary OR for enums
template<typename T>
inline T operator|(T s1, T s2)
{
	return T(int(s1) | int(s2));
}

//! \brief Binary assignment-OR for enums
template<typename T>
inline T& operator|=(T& s1, T s2)
{
	s1 = s1 | s2;
	return s1;
}

//! \brief Binary AND for enums
template<typename T>
inline T operator&(T s1, T s2)
{
	return T(int(s1) & int(s2));
}

//! \brief Binary assignment-AND for enums
template<typename T>
inline T& operator&=(T& s1, T s2)
{
	s1 = s1 & s2;
	return s1;
}

//! \brief Binary XOR for enums
template<typename T>
inline T operator^(T s1, T s2)
{
	return T(int(s1) ^ int(s2));
}

//! \brief Binary assignment-XOR for enums
template<typename T>
inline T& operator^=(T& s1, T s2)
{
	s1 = s1 ^ s2;
	return s1;
}

//! \brief Binary NOT for enums
template<typename T>
inline T operator~(T s)
{
	return T(~int(s));
}

//! \brief Check whether the state has a certain flag set.
//!
//! If flags are ORed, checked that all are set.  Other flags may be set,
//! too, use result_is_exactly if you don't want this.
//!
//! \param[in] state are the flags to be checked against.
//! \param[in] flags are the flags to be checked for.
template<typename T>
inline bool state_has_all(T state, T flags)
{
	return (state & flags) == flags;
}

//! \brief Check whether the state has any of the ORed flags set.
//!
//! Assuming ORed flags, check whether at least one is set.
//!
//! \param[in] state are the flags to be checked against.
//! \param[in] flags are the flags to be checked for.
template<typename T>
inline bool state_has_some(T state, T flags)
{
	return (state & flags) != T::empty;
}

//! \brief Check whether the result has only the specified flags set.
//!
//! Assuming ORed flags, check whether only these flags are set.
//!
//! \param[in] state are the flags to be checked against.
//! \param[in] flags are the flags to be checked for.
template<typename T>
inline bool state_has_only(T state, T flags)
{
	return (state & ~flags) != T::empty;
}

//! \brief Return a T with all bits set that are set in flags or in state.
template<typename T>
inline T set(T state, T flags)
{
	return state | flags;
}

//! \brief Return a T with all bits set that are set in state but not flags.
template<typename T>
inline T unset(T state, T flags)
{
	return state & ~flags;
}

} // namespace study

#endif // INCLUDE_STUDY_ENUMUTILS_HPP

