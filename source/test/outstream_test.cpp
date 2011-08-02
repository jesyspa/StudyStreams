#include "study/outstream.hpp"
#include <sstream>
#include <gtest/gtest.h>
#include "study/lessoninterface.hpp"
#include "test/lesson_mock.hpp"
#include "study/logstream.hpp"

using namespace study;

TEST(OutStream, DefaultConstructor)
{
	OutStream out;
	EXPECT_FALSE(out.has_lesson()) << "OutStream incorrectly marked as connected.";
}

TEST(OutStream, SetLessonInterface)
{
	OutStream out;
	LessonMock* p = new LessonMock();
	LessonInterface l(p);
	EXPECT_EQ(&out.set_interface(l), &out) << "Fluid interface error.";
	EXPECT_TRUE(out.has_lesson()) << "OutStream incorrectly marked as disconnceted.";
}

TEST(OutStream, PassInput)
{
	OutStream out;
	LessonMock* p = new LessonMock();
	p->expect("A B C 4 5");
	LessonInterface l(p);
	out.set_interface(l);
	EXPECT_TRUE(out.has_lesson()) << "OutStream incorrectly marked as disconnceted.";
	out << "A B C " << 4 << ' ' << 5 << endl;
}

TEST(OutStream, Flush)
{
	OutStream out;
	LessonMock* p = new LessonMock();
	p->expect("A B C 4 5");
	LessonInterface l(p);
	out.set_interface(l);
	out << "A B C " << 4 << ' ' << 5;
	out.flush();
}

