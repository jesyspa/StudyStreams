#ifndef INCLUDE_STUDY_IO_HPP
#define INCLUDE_STUDY_IO_HPP

#include "study/outstream.hpp"
#include "study/instream.hpp"
#include "study/logstream.hpp"
#include "study/endline.hpp"

namespace study
{

//! \brief Default stream for outputting data to lessons.
extern OutStream cout;

//! \brief Default stream for receiving input from lessons.
extern InStream cin;

//! \brief Default stream for the user to provide own output with.
extern LogStream cerr;

//! \brief Default stream for the user to log things with.
//!
//! \warning Not implemented, usage will lead to a segfault.
extern LogStream clog;

//! \brief Default stream for the lesson to output with.
extern LogStream lout;

//! \brief Default stream for outputting data to lessons.
extern EndLine endl;

} // namespace study

#endif // INCLUDE_STUDY_IO_HPP

