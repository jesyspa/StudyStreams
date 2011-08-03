#include "study/lessoninterface.hpp"
#include "study/linearlesson.hpp"

using namespace study;
using namespace study::keywords;

struct HelloWorldLesson :
	LinearLesson
{

	void construct()
	{
		log().set_prefix("--| ");
		Exercise* e;
		e = new Exercise(
			"[Demonstration]",
			_answer="Hello world!"
		);
		add_exercise(e);
		e = new Exercise(
			"[Reality]",
			_answer="Hello universe!"
		);
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
		log() << "End of exercise." << study::endl;
	}

};

LessonInterface hello_world(new HelloWorldLesson);

