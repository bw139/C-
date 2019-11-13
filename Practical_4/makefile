# Makefile

# the C++ compiler
CXX     = g++
CXXVERSION = $(shell g++ --version | grep ^g++ | sed 's/^.* //g')

# options to pass to the compiler
CXXFLAGS = -O0 -g3

ifeq "$(CXXVERSION)" "4.6.3"
	CXXFLAGS += -std=c++0x
else
	CXXFLAGS += -std=c++11
endif

all: main

main:	main.cpp Student.o Department.o
	$(CXX) $(CXXFLAGS) main.cpp Student.o Department.o -o main

Student.o:	Student.cpp Student.h 
	$(CXX) $(CXXFLAGS) -c Student.cpp 

Department.o:	Department.cpp Department.h 
	$(CXX) $(CXXFLAGS) -c Department.cpp 

deepclean: 
	-rm -f *~ *.o main main.exe

clean:
	-rm -f *~ *.o 

