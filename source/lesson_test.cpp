#include "study/lesson.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include "test/lesson_mock.hpp"

using namespace study;

TEST(Lesson, Construct)
{
	LessonMock l; // Should suffice, as it does not overload anything relevant.
}

