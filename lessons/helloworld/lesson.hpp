#ifndef HELLOWORLD_LESSON_HPP
#define HELLOWORLD_LESSON_HPP

#include <study/linearlesson.hpp>

struct HelloWorldLesson :
	study::LinearLesson
{
	void construct();
	void welcome();
	void part();
	int solution(int argc, char* argv[]);
};

#endif 

