#include <study.hpp>

// Solution #3
// Lesson:  Find average of several doubles
// Every exercise will consist of a number of non-negative doubles.  After all
// are read, the stream will become invalid.

// Syntax: Check stream state to see if there is more data for this exercise,
// check the lesson to check if there are more exercises.  Lesson created with
// a macro.

int main()
{
        START_LESSON(lesson);
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

