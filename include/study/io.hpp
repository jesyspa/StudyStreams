#ifndef INCLUDE_STUDY_IO_HPP
#define INCLUDE_STUDY_IO_HPP

#include "outstream.hpp"
#include "instream.hpp"
#include "logstream.hpp"

namespace study
{

extern OutStream cout;
extern InStream cin;
extern LogStream cerr;
extern LogStream clog;
extern LogStream lout;
extern EndLine endl;

} // namespace study

#endif // INCLUDE_STUDY_IO_HPP

