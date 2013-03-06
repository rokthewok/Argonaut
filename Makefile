incl=include/
src=src/

main.o : main.c JsonScanner.o
	g++ -c main.c
JsonScanner.o : JsonScanner.h JsonScanner.cpp StreamReader.h StringReader.h Reader.h SyntaxException.h
	g++ -c JsonScanner.cpp JsonScanner.h StreamReader.h StringReader.h Reader.h SyntaxException.h
Reader.o : 
