#
# PROGRAM:    Assignment
# PROGRAMMER: Connor Pekovic
# LOGON ID:   z1761994
# DATE DUE:   October 6th, 2017.
#

CC=g++
CFLAG= -c -Wall

all:assignment6.exe

assignment6.exe: assignment5.o assignment6.o assignment6main.o
	$(CC) assignment5.o assignment6.o assignment6main.o -o assignment6.exe

assignment5.o:assignment5.cc
	$(CC) $(CFLAG) assignment5.cc

assignment6.o:assignment6.cc
	$(CC) $(CFLAG) assignment6.cc

assignment6main.o:assignment6main.cc
	$(CC) $(CFLAG) assignment6main.cc

clean:
	rm -rf *o assignment6.exe
