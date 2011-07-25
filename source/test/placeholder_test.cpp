#include "study/placeholder.hpp"
#include <gtest/gtest.h>

using study::replace_with_a_;
using study::replace_with_an_;

TEST(Placeholder, Generic)
{
	EXPECT_EQ(replace_with_a_<unsigned int>(), 0) << "unsigned int";
	EXPECT_EQ(replace_with_a_<float>(), 0.0) << "float";
	EXPECT_EQ(replace_with_a_<bool>(), false) << "bool";
}

TEST(Placeholder, Specialised)
{
	EXPECT_EQ(replace_with_a_<char>(), '?') << "char";
	EXPECT_EQ(replace_with_a_<int>(), 314159) << "int";
	EXPECT_EQ(
		replace_with_a_<std::string>(),
		"<Placeholder std::string>") << "std::string";
	EXPECT_EQ(
		replace_with_a_<char const*>(),
		"<Placeholder const char*>") << "char const*";
	EXPECT_EQ(replace_with_a_<double>(), 3.14159) << "double";
}

TEST(Placeholder, Alias)
{
	EXPECT_EQ(replace_with_an_<unsigned int>(), 0) << "unsigned int";
	EXPECT_EQ(replace_with_an_<float>(), 0.0) << "float";
	EXPECT_EQ(replace_with_an_<bool>(), false) << "bool";
	EXPECT_EQ(replace_with_an_<char>(), '?') << "char";
	EXPECT_EQ(replace_with_an_<int>(), 314159) << "int";
	EXPECT_EQ(
		replace_with_an_<std::string>(),
		"<Placeholder std::string>") << "std::string";
	EXPECT_EQ(
		replace_with_an_<char const*>(),
		"<Placeholder const char*>") << "char const*";
	EXPECT_EQ(replace_with_an_<double>(), 3.14159) << "double";
}
