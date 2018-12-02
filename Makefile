CXX = g++
CXXFLAGS = -Wall -g

merge_test: merge.test.o
	$(CXX) $(CXXFLAGS) -o merge merge.test.o

merge.test.o: test/merge.test.cpp lib/merge.hpp
	$(CXX) $(CXXFLAGS) -c test/merge.test.cpp
