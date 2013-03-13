# Argonaut C++ Makefile

VPATH = src:include:bin

CFLAGS = -g -Iinclude -std=c++11

incl = include/
src = src/
bin = bin/

obj = main.o JsonScanner.o SyntaxException.o StreamReader.o StringReader.o
binobj = $(bin)main.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)SyntaxException.o

argonaut : $(obj)
	g++ -o argonaut $(binobj)
main.o : main.c JsonScanner.o
	g++ $(CFLAGS) -c $(src)main.c -o $(bin)main.o
JsonScanner.o : JsonScanner.h JsonScanner.cpp Reader.h SyntaxException.h
	g++ $(CFLAGS) -c $(src)JsonScanner.cpp -o $(bin)JsonScanner.o
Reader.o : Reader.h Reader.cpp
	g++ $(CFLAGS) -c $(src)Reader.cpp -o $(bin)Reader.o
clean :
	rm -f bin/*.o argonaut
