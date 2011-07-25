#ifndef LESSON_HELLOWORLD_LOADER_HPP
#define LESSON_HELLOWORLD_LOADER_HPP

#include "study/lessonloader.hpp"

struct HelloWorldLoader :
	study::LessonLoader
{
	void construct();
	void welcome();
	void end_exercise();
	void part();
	void destruct();
};

#endif // LESSON_HELLOWORLD_LOADER_HPP
