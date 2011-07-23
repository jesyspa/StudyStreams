#include <fstream>
#include <iostream>
#include "study/io.hpp"

namespace study
{

OutStream cout;
InStream cin;
LogStream cerr(std::cerr);
LogStream clog;
LogStream lout(std::cout);
EndLine endl;

} // namespace study

