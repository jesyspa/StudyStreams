Help("""
'scons debug' for debug build
'scons release' for release build
""")

########  FLAGS  ########

flags = {
	'cpp': ["-Wall", "-Wextra", "-std=c++0x"],
	'debug': ["-O0", "-ggdb"],
	'release': "-O2",
	'frame': "-I#include/",
	'test': ["-I#include/", "-lgtest", "-lpthread", "-L#lib/", "-ldbgstudy"],
}

Export('flags')

######  END FLAGS  ######

##### ENVIRONMENTS  #####

base_env = Environment(CXX="g++", CPPFLAGS=flags['cpp'])

Export('base_env')

#### END ENVIRONMENTS ###

SConscript("source/SConscriptDebug", variant_dir='dbgbuild')
SConscript("source/SConscriptRelease", variant_dir='relbuild')

Default('runtests')

