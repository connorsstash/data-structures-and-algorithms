# Program    : Assignment 2 for 340
#
# Programmer : Connor Pekovic

CC = g++
CCFLAGS = -Wall -std=c++11

assignment2: assignment2.o
	$(CC) $(CCFLAGS) -o assignment2 assignment2.o

assignment2.o: assignment2.cc
	$(CC) $(CCFLAGS) -c assignment2.cc

clean:
	-rm *.o assignment2
