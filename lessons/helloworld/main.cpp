#include <study.hpp>
#include "lesson.hpp"

int MAIN(int argc, char* argv[])
{
	// "Hello world!" turns into a char const* automatically.
	study::cout << replace_with_a_<char const*>() << study::endl;
	return 0;
}

