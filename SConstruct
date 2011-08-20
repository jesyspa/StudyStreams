Help("""
'scons debug' for debug build
'scons release' for release build
""")

########  FLAGS  ########

flags = {
	'cpp': ["-Wall", "-Wextra", "-std=c++0x"],
	'debug': ["-O0", "-ggdb", "-D_GLIBCXX_DEBUG"],
	'release': ["-O2", "-DNDEBUG"],
	'frame': "-I#include/",
	'test': ["-I#include/", "-lgtest", "-lpthread", "-L#lib/"],
}

Export('flags')

######  END FLAGS  ######

##### ENVIRONMENTS  #####

base_env = Environment(CXX="g++", CPPFLAGS=flags['cpp'])

dbg_frame_env = base_env.Clone()
dbg_frame_env.MergeFlags([flags['debug'], flags['frame']])

rel_frame_env = base_env.Clone()
rel_frame_env.MergeFlags([flags['release'], flags['frame']])

Export('base_env')

#### END ENVIRONMENTS ###

dbg_exports = {
	'env': dbg_frame_env,
	'prefix': 'dbg',
}

rel_exports = {
	'env': rel_frame_env,
	'prefix': '',
} 

SConscript("source/SConscript", exports=dbg_exports, variant_dir='.dbgbuild')
SConscript("source/SConscript", exports=rel_exports, variant_dir='.relbuild')

Default('dbgruntests')

