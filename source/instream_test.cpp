#include "study/instream.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(InStream, Constructor)
{
	study::InStream in;
}

TEST(InStream, RightShift)
{
	study::InStream in;
	in.set_input("A 5 3.5 BOO");
	char c;
	int i;
	double d;
	std::string s;
	in >> c >> i >> d >> s;
	EXPECT_EQ('A', c);
	EXPECT_EQ(5, i);
	EXPECT_EQ(3.5, d);
	EXPECT_EQ("BOO", s);
}

TEST(InStream, ToBool)
{
	study::InStream in;
	EXPECT_TRUE(in);
	in.set_input("B");
	std::string s;
	EXPECT_TRUE(in >> s);
	EXPECT_FALSE(in >> s);
}

