#include <study.hpp>

// This lesson demonstrates the basics of using study::cin when no LessonInterface
// object is provided.
//
// Integers will be inputted sequentially.  Output `even' when an even integer
// is inputted, and `odd' otherwise.  All input provided will be valid.
int main()
{
	int i; // Input will go here.
	while (study::cin >> i) // This will try to read one integer at a time,
	{                       // until there is nothing more to be read.
		if (i % 2 == 0) // If i is even
			study::cout << replace_with_a<const char*> << study::endl;
		else // if i is not even
			study::cout << replace_with_a<const char*> << study::endl;
	}
}

