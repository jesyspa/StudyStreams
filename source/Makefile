include ../constants.mk

all: libstudy.a

source: libstudy.a

outstream.o : outstream.cpp
	$(CXX) $(CXX_SOURCE_FLAGS) $(CXX_FLAGS) -c -o outstream.o outstream.cpp
	
instream.o : instream.cpp
	$(CXX) $(CXX_SOURCE_FLAGS) $(CXX_FLAGS) -c -o instream.o instream.cpp

lesson.o : lesson.cpp
	$(CXX) $(CXX_SOURCE_FLAGS) $(CXX_FLAGS) -c -o lesson.o lesson.cpp

io.o : io.cpp
	$(CXX) $(CXX_SOURCE_FLAGS) $(CXX_FLAGS) -c -o io.o io.cpp

libstudy.a : outstream.o instream.o lesson.o io.o
	mkdir -p ../lib
	ar rcs ../lib/libstudy.a outstream.o instream.o lesson.o io.o 
	ranlib ../lib/libstudy.a

tests: test
	./test

outstream_test.o : outstream_test.cpp
	$(CXX) $(CXX_TEST_FLAGS) $(CXX_FLAGS) -c -o outstream_test.o outstream_test.cpp
	
instream_test.o : instream_test.cpp
	$(CXX) $(CXX_TEST_FLAGS) $(CXX_FLAGS) -c -o instream_test.o instream_test.cpp

lesson_test.o : lesson_test.cpp
	$(CXX) $(CXX_TEST_FLAGS) $(CXX_FLAGS) -c -o lesson_test.o lesson_test.cpp

io_test.o : io_test.cpp
	$(CXX) $(CXX_TEST_FLAGS) $(CXX_FLAGS) -c -o io_test.o io_test.cpp

placeholder_test.o : placeholder_test.cpp
	$(CXX) $(CXX_TEST_FLAGS) $(CXX_FLAGS) -c -o placeholder_test.o placeholder_test.cpp

test_main.o : test_main.cpp
	$(CXX) $(CXX_TEST_FLAGS) $(CXX_FLAGS) -c -o test_main.o test_main.cpp

test : libstudy.a outstream_test.o instream_test.o lesson_test.o io_test.o placeholder_test.o test_main.o
	$(CXX) -o test outstream_test.o instream_test.o lesson_test.o io_test.o placeholder_test.o test_main.o $(LINK_TEST_FLAGS)

.PHONY: clean
clean:
	rm -f *.o *.a ../lib/libstudy.a test

