# Program    : assignment 3 for 340-3
#
# Programmer : Connor Pekovic - Northern Illinois University

CC = g++
CCFLAGS = -Wall -std=c++11

assignment3.exe: assignment3.o
	$(CC) $(CCFLAGS) -o assignment3.exe assignment3.o

assignment3.o: assignment3.cc
	$(CC) $(CCFLAGS) -c assignment3.cc

clean:
	-rm *.o assignment3.exe
