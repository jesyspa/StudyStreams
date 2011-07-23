#ifndef INCLUDE_STUDY_LESSONLOADER_HPP
#define INCLUDE_STUDY_LESSONLOADER_HPP

#include <boost/utility.hpp>
#include "exercise.hpp"

namespace study
{

class LessonLoader :
	boost::noncopyable
{
	LessonLoader();
	~LessonLoader();

};

} // namespace study

#endif // INCLUDE_STUDY_LESSONLOADER_HPP
