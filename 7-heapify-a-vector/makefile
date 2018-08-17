CC=g++
CFLAG= -c -Wall

assignment7.exe: assignment7.o
	$(CC) assignment7.o -o assignment7.exe

assignment7.o: assignment7.cc
	$(CC) $(CFLAG) assignment7.cc

clean:
	rm -rf *o assignment7.exe
