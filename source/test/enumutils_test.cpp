#include "study/enumutils.hpp"
#include <gtest/gtest.h>

using namespace study;

namespace {

enum class A {
	a = 0,
	b = 1 << 0,
	c = 1 << 1,
	d = 1 << 2,
	e = 1 << 3,
	f = 1 << 4
};

} // namespace

TEST(EnumUtils, StateHasAll)
{
	ASSERT_TRUE(state_has_all(A::b, A::b));
	ASSERT_FALSE(state_has_all(A::b, A::d));
	ASSERT_TRUE(state_has_all(A::b | A::c, A::b));
	ASSERT_TRUE(state_has_all(A::b | A::c, A::b | A::c));
	ASSERT_FALSE(state_has_all(A::b, A::b | A::c));
}

