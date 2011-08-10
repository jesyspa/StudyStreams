#include "study/guardedexercise.hpp"
#include <gtest/gtest.h>
#include <boost/scoped_ptr.hpp>

using namespace study;

TEST(GuardedExercise, GetInput)
{
	boost::scoped_ptr<Exercise> e(new GuardedExercise);
	e->set_input("ABCD").set_name("DEFG");
	ASSERT_EQ(e->get_name(), "DEFG") << "Name set incorrectly.";
	ASSERT_EQ(e->get_input(), "ABCD GUARD\n TEXT\n")
		<< "Guard text not added properly.";
}

