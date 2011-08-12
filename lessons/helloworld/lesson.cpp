#include <study/lessoninterface.hpp>
#include <study/linearlesson.hpp>
#include <study/stringutils.hpp>

using namespace study;

struct HelloWorldLesson :
	LinearLesson
{
	void construct()
	{
		log().set_prefix("--| ");
		Exercise* e;
		e = &(new Exercise)->
			set_name("[Demonstration]").
			set_answer("Hello world!")
		add_exercise(e);
		e = &(new Exercise)->
			set_name("[Reality]").
			set_answer("Hello universe!").
			set_compare(loose_compare)
		add_exercise(e);
	}

	void welcome()
	{
		log() << "Welcome to the first lesson in StudyStreams.\n" << study::endl;
		log() << "Rather unsuprisingly, this is a Hello World program. "
			<< "See the helloworld.cpp file for instructions.\n" << study::endl;
	}

	void part()
	{
		log() << "End of lesson." << study::endl;
	}

};

LessonInterface hello_world(new HelloWorldLesson);

