#include "study/lessoninterface.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include "test/lessoninterface_mock.hpp"

using namespace study;

TEST(LessonInterface, Construct)
{
	LessonMock l; // Should suffice, as it does not overload anything relevant.
}

