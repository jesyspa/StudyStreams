#include <study.hpp>
#include "lesson.hpp"

// Solution #4
// Lesson:  Find average of several doubles
// Every exercise will consist of a number of non-negative doubles.  After all
// are read, the stream will become invalid.

// Syntax: Check stream state to see if there is more data for this exercise.
// MAIN is called externally, once for every exercise.

int MAIN(int argc, char* argv[])
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
        return 0;
}

