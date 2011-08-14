#include <study/lessoninterface.hpp>
#include <study/linearlesson.hpp>
#include <study/stringutils.hpp>
#include "lesson.hpp"

using namespace study;

void HelloWorldLesson::construct()
{
	log().set_prefix("--| ");
	add_exercise(&(new Exercise)->
		set_name("Welcoming Lesson").
		set_answer("Hello world!")
		set_compare(loose_compare));
}

void HelloWorldLesson::welcome()
{
	log() << "Welcome to the first lesson in StudyStreams.\n" << study::endl;
	log() << "Rather unsuprisingly, this is a Hello World program. "
		<< "See the helloworld.cpp file for instructions.\n" << study::endl;
}

void HelloWorldLesson::part()
{
	log() << "End of lesson." << study::endl;
}

int main()
{
	LessonInterface lesson(new HelloWorldLesson);
	lesson.run();
}

