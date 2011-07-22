#include <study.hpp>

int main()
{
	Lesson lesson("helloworld");
	study::cout << "Hello world!" << study::endl;
	// "Hello world!" turns into a char const* automatically.
	// Now, say hello to the universe.
	study::cout << replace_with_a_<char const*>() << study::endl;
	return lesson.result();
}

