#include "study/outstream.hpp"
#include <sstream>
#include <gtest/gtest.h>
#include "test/lessoninterface_mock.hpp"
#include "study/logstream.hpp"

TEST(OutStream, DefaultConstructor)
{
	study::OutStream out;
	EXPECT_FALSE(out.has_lesson()) << "OutStream incorrectly marked as connected.";
}

TEST(OutStream, SetLessonInterface)
{
	study::OutStream out;
	study::LessonInterfaceMock l;
	EXPECT_EQ(&out.set_interface(l), &out) << "Fluid interface error.";
	EXPECT_TRUE(out.has_lesson()) << "OutStream incorrectly marked as disconnceted.";
}

TEST(OutStream, PassInput)
{
	study::OutStream out;
	study::LessonInterfaceMock l;
	out.set_interface(l);
	EXPECT_TRUE(out.has_lesson()) << "OutStream incorrectly marked as disconnceted.";
	out << "A B C " << 4 << ' ' << 5 << study::endl;
	EXPECT_EQ(l.view_submition(), "A B C 4 5") << "Submition passed incorrectly.";
}

TEST(OutStream, Flush)
{
	study::OutStream out;
	study::LessonInterfaceMock l;
	out.set_interface(l);
	out << "A B C " << 4 << ' ' << 5;
	out.flush();
	EXPECT_EQ(l.view_submition(), "A B C 4 5") << "Submition passed incorrectly.";
}

