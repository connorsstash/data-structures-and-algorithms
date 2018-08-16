# Assignment: Assignment4   
# Programmer: Connor Pekovic 
# Z - ID    : Z1761994
# Due       : Feb 22, 2017 

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment4.exe: assignment4.o stack.o
	g++ $(CCFLAGS) -o assignment4.exe assignment4.o stack.o

# Rule to compile source code file to object code
assignment4.o: assignment4.cc assignment4.h
	g++ $(CCFLAGS) -c assignment4.cc

# Rule to compile source code file to object code
stack.o: stack.cc assignment4.h
	g++ $(CCFLAGS) -c stack.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment4.exe
