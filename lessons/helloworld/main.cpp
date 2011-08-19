#include <study.hpp>
#include "lesson.hpp"

// Welcome to the first lesson of StudyStreams!
//
// In order to complete the lessons, you will need to modify the main.cpp
// files in the lesson directories.  These will already have some basic code
// for you to modify:  it'll give you an idea of what is required, but feel
// free to add any extra code you think is necessary.  Do note that any files
// you want compiled should have a cpp, cxx, c++, or cc extension.
//
// The MAIN function will be called for each exercise in the lesson.  Treat it
// as if it was the standard main function:  the only differences are that the
// parameters must be `int argc, char* argv[]', and there is no implicit
// `return 0;' at the end.
//
// You will be submitting your answers to the lesson by using the study::cout
// object.  This works exactly like writing to std::cout, but your answers
// won't show up on the screen: instead, they'll be processed internally, and
// compared to the expected answer.  Occasionally, you'll see replace_with_a_
// or replace_with_an_ called somewhere.  Replace these with a variable or
// constant of the type between the < and >.
//
// Finally, once you're done editing this file, run `scons' in the directory
// in which main is in, and execute the `helloworld' file. 

int MAIN(int argc, char* argv[])
{
	// "Hello world!" turns into a char const* automatically.
	study::cout << replace_with_a_<char const*>() << study::endl;
	return 0;
}

