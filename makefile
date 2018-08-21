######################################################################
# Program name: Proj1
# Author: Kristen Harrison
# Date: 1 July 2017
# Description: CS162, Project 1. This makefile can be run with three commands:
# 1. "make" makes the program Lab1   2. "make clean" cleans the directory   
# 3. "make memcheck" runs valgrind to test for memory leaks
######################################################################

# target: dependencies
# [tab] recipe


CXX = g++
CXXFLAGS = -std=c++0x -g -Wall
VALFLAGS = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

OBJS = main.o Ant.o Board.o validateInput.o
HEADERS = Ant.hpp Board.hpp validateInput.hpp



Proj1: $(OBJS) $(HEADERS)
	$(CXX) $(OBJS) -o Proj1

main.o: $(HEADERS) main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

Ant.o: Ant.hpp Ant.cpp 
	$(CXX) $(CXXFLAGS) -c Ant.cpp

Board.o: Board.hpp Ant.hpp Board.cpp 
	$(CXX) $(CXXFLAGS) -c Board.cpp

validateInput.o: validateInput.hpp validateInput.cpp
	$(CXX) $(CXXFLAGS) -c  validateInput.cpp

clean:
	rm *.o Proj1

memcheck: Proj1
	valgrind $(VALFLAGS) ./Proj1
