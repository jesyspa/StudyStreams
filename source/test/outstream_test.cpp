#include "study/outstream.hpp"
#include <sstream>
#include <gtest/gtest.h>
#include "test/lesson_mock.hpp"
#include "study/logstream.hpp"

TEST(OutStream, DefaultConstructor)
{
	study::OutStream out;
	EXPECT_FALSE(out.has_lesson()) << "OutStream incorrectly marked as connected.";
}

TEST(OutStream, SetLesson)
{
	study::OutStream out;
	study::LessonMock l;
	EXPECT_EQ(&out.set_lesson(l), &out) << "Fluid interface error.";
	EXPECT_TRUE(out.has_lesson()) << "OutStream incorrectly marked as disconnceted.";
}

TEST(OutStream, PassInput)
{
	study::OutStream out;
	study::LessonMock l;
	EXPECT_EQ(&out.set_lesson(l), &out) << "Fluid interface error.";
	EXPECT_TRUE(out.has_lesson()) << "OutStream incorrectly marked as disconnceted.";
	out << "A B C " << 4 << ' ' << 5 << study::endl;
	EXPECT_EQ(l.view_submition(), "A B C 4 5") << "Submition passed incorrectly.";
}

