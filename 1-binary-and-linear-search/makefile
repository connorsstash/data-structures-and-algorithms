# Program    : Assignment 1 for 340
#
# Programmer : Connor Pekovic

CC = g++
CCFLAGS = -Wall -std=c++11

Assign1.exe: Assign1.o
	$(CC) $(CCFLAGS) -o Assign1.exe Assign1.o

Assign1.o: Assign1.cc
	$(CC) $(CCFLAGS) -c Assign1.cc

clean:
	-rm *.o Assign1.exe
