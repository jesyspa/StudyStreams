#include "study/placeholder.hpp"
#include <gtest/gtest.h>

using study::replace_with_a_;
using study::replace_with_an_;

TEST(Placeholder, Generic)
{
	ASSERT_EQ(replace_with_a_<unsigned int>(), 0) << "unsigned int";
	ASSERT_EQ(replace_with_a_<float>(), 0.0) << "float";
	ASSERT_EQ(replace_with_a_<bool>(), false) << "bool";
}

TEST(Placeholder, Specialised)
{
	ASSERT_EQ(replace_with_a_<char>(), '?') << "char";
	ASSERT_EQ(replace_with_a_<int>(), 314159) << "int";
	ASSERT_EQ(
		replace_with_a_<std::string>(),
		"<Placeholder std::string>") << "std::string";
	ASSERT_EQ(
		replace_with_a_<char const*>(),
		"<Placeholder const char*>") << "char const*";
	ASSERT_EQ(replace_with_a_<double>(), 3.14159) << "double";
}

TEST(Placeholder, Alias)
{
	ASSERT_EQ(replace_with_an_<unsigned int>(), 0) << "unsigned int";
	ASSERT_EQ(replace_with_an_<float>(), 0.0) << "float";
	ASSERT_EQ(replace_with_an_<bool>(), false) << "bool";
	ASSERT_EQ(replace_with_an_<char>(), '?') << "char";
	ASSERT_EQ(replace_with_an_<int>(), 314159) << "int";
	ASSERT_EQ(
		replace_with_an_<std::string>(),
		"<Placeholder std::string>") << "std::string";
	ASSERT_EQ(
		replace_with_an_<char const*>(),
		"<Placeholder const char*>") << "char const*";
	ASSERT_EQ(replace_with_an_<double>(), 3.14159) << "double";
}
