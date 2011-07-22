include ../../constants.mk

NAME = "helloworld"

all: main

main.o : main.cpp
	$(CXX) -c -o main.o main.cpp $(CXX_LESSON_FLAGS) $(CXX_FLAGS) 

main : main.o
	$(CXX) -o main main.o $(LINK_LESSON_FLAGS) $(LINK_FLAGS) 

.PHONY: clean
clean:
	rm -f *.o main

