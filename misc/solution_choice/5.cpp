#include <study.hpp>
#include "lesson/average.hpp"

// Solution #5
// Lesson:  Find average of several doubles
// Every exercise will consist of a number of non-negative doubles.  After all
// are read, the stream will become invalid.

// Syntax: Check stream state to see if there is more data for this exercise,
// check the lesson to check if there are more exercises.  Lesson created with
// a function defined by the lesson.

int main()
{
        study::PublicLesson lesson = average.get_public(); // Or Average::get_lesson()?
        while(lesson) // Will be false after the last exercise
        {
                double d;
                double total = 0.0;
                int count = 0;
                while (study::cin >> d) // Will be true until all data is read.
                {
                        total += d;
                        ++count;
                }
                study::cout << (total/count) << study::endl; // Submits the answer.
        }
}

