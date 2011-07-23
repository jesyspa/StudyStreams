########  FLAGS  ########

cpp_flags = ["-Wall", "-Wextra", "-std=c++0x"]
debug_flags = "-O0 -ggdb"
release_flags = "-O2"
frame_flags = "-Iinclude/"
test_flags = "-Iinclude/ -lgtest -lpthread -L. -ldbgstudy"
lesson_flags = "-Iinclude/"

######  END FLAGS  ######

#######  SOURCES  #######

# Frame
frame_sources_base = Split("""
exercise.cpp
instream.cpp
io.cpp
lesson.cpp
lessonloader.cpp
logstream.cpp
outstream.cpp
""")

frame_sources = ["source/" + x for x in frame_sources_base]

# Test
test_sources = Glob("source/*_test.cpp") + ["source/test_main.cpp"]

# Lesson

#####  END SOURCES  #####

##### ENVIRONMENTS  #####

base_env = Environment(CXX="g++", CPPFLAGS=cpp_flags)
dbg_frame_env = base_env.Clone()
dbg_frame_env.MergeFlags([debug_flags, frame_flags])

dbg_frame_env.StaticLibrary('dbgstudy', frame_sources)

test_env = base_env.Clone()
test_env.MergeFlags([debug_flags, test_flags])
test_env.Program("test", test_sources)

#### END ENVIRONMENTS ###
