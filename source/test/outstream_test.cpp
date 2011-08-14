#include "study/outstream.hpp"
#include <sstream>
#include <gtest/gtest.h>
#include "study/lessoninterface.hpp"
#include "study/logstream.hpp"

using namespace study;

TEST(OutStream, DefaultConstructor)
{
	OutStream out;
	EXPECT_FALSE(out.claimed()) << "OutStream incorrectly marked as claimed.";
}

TEST(OutStream, SetLessonInterface)
{
	OutStream out;
	out.claim();
	EXPECT_EQ(&out.claim(), &out) << "Fluid interface error.";
	EXPECT_TRUE(out.claimed()) << "OutStream incorrectly marked as unclaimed.";
}

TEST(OutStream, PassInput)
{
	OutStream out;
	out << "A B C " << 4 << ' ' << 5 << endl;
	EXPECT_EQ(out.retrieve(), "A B C 4 5\n");
}

#if 0
// Flush has no effect at the moment, so nothing to test.
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
#endif

