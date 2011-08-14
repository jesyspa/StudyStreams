#include <study.hpp>

// Solution #1
// Lesson:  Find average of several doubles
// Every exercise will consist of a number of non-negative doubles, followed
// by a -1.0.  Once this is read, the average of the doubles should be printed
// (the -1.0 should not be included in the count).

// Syntax: Check stream state for end of lesson, check values for end of exercise.
int main()
{
        while(study::cin) // Will be false after the last exercise
        {
                double d;
                double total = 0.0;
                int count = 0;
                while (study::cin >> d && d != -1.0) // study::cin >> d will always be true.
                {
                        total += d;
                        ++count;
                }
                study::cout << (total/count) << study::endl; // Submits the answer.
        }
}

