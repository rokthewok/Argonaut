# Argonaut C++ Makefile
VPATH = src:include:test/include:test/src

CFLAGS = -g -Iinclude -std=c++11
TESTCFLAGS = -g -Iinclude -Itest/include -std=c++11

incl = include/
src = src/
bin = bin/
test = test/

obj = argonaut.o JsonScanner.o Reader.o JsonToken.o #SyntaxException.o
binobj = $(bin)argonaut.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)JsonToken.o #$(bin)SyntaxException.o
testobj = JsonScannerTests.o test.o JsonScanner.o Reader.o JsonToken.o BaseTests.o
testbinobj =  $(bin)JsonScannerTests.o $(bin)test.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)JsonToken.o $(bin)BaseTests.o

argonaut : $(obj)
	g++ -o argonaut $(binobj)
argonaut.o : argonaut.cpp JsonScanner.o
	g++ $(CFLAGS) -c $(src)argonaut.cpp -o $(bin)argonaut.o
#SyntaxException.o : SyntaxException.h
#	g++ $(CFLAGS) -c $(incl)SyntaxException.h -o $(bin)SyntaxException.o
JsonScanner.o : JsonScanner.h JsonScanner.cpp Reader.o SyntaxException.h JsonToken.h JsonToken.o
	g++ $(CFLAGS) -c $(src)JsonScanner.cpp -o $(bin)JsonScanner.o
JsonToken.o : JsonToken.h JsonTypes.h JsonToken.cpp
	g++ $(CFLAGS) -c $(src)JsonToken.cpp -o $(bin)JsonToken.o
Reader.o : Reader.h Reader.cpp
	g++ $(CFLAGS) -c $(src)Reader.cpp -o $(bin)Reader.o
test : $(testobj)
	# TODO build all test classes and main test file
	g++ -o test_argonaut $(testbinobj)
test.o : test.cpp JsonScannerTests.o
	g++ $(TESTCFLAGS) -c $(test)src/test.cpp -o $(bin)test.o
BaseTests.o : BaseTests.h BaseTests.cpp
	g++ $(TESTCFLAGS) -c $(test)src/BaseTests.cpp -o $(bin)BaseTests.o
JsonScannerTests.o : JsonScannerTests.h JsonScannerTests.cpp JsonScanner.o
	g++ $(TESTCFLAGS) -c $(test)src/JsonScannerTests.cpp -o $(bin)JsonScannerTests.o
clean :
	rm -f bin/*.o argonaut test_argonaut
