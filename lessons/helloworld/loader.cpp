#include "study/lesson.hpp"
#include "study/stringutils.hpp"
#include "loader.hpp"

using namespace study;

Lesson hello_world(new HelloWorldLoader);

void HelloWorldLoader::construct()
{
	log().set_prefix("--| ");
	Exercise* e;
	e = new Exercise(
		"[Demonstration]",
		"Hello world!\n",
		"", "", ""
	);
	add_exercise_at_end(e);
	e = new Exercise(
		"[Reality]",
		"Hello universe!\n",
		"", "", ""
	);
	add_exercise_at_end(e);
}

void HelloWorldLoader::welcome()
{
	log() << "Welcome to the first lesson in StudyStreams.\n" << study::endl;
	log() << "Rather unsuprisingly, this is a Hello World program. "
		<< "See the helloworld.cpp file for instructions.\n" << study::endl;
}

void HelloWorldLoader::end_exercise()
{
	if (current_exercise()->result_is(Exercise::State::success)) {
		log() << "Congratulations!  Exercise "
			<< current_exercise()->get_name() << " passed.\n" << study::endl;
	} else {
		log() << "Expected: \""
			<< string_normalise(current_exercise()->get_answer())
			<< "\"" << study::endl;
		log() << "Got: \""
			<< string_normalise(current_exercise()->get_received())
			<< "\"" << study::endl;
		log() << "Please try again.\n" << study::endl;
	}
}

void HelloWorldLoader::part()
{
	log() << "End of exercise." << study::endl;
}

void HelloWorldLoader::destruct()
{
	
}

