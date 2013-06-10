# Argonaut C++ Makefile
VPATH = src:include:test/include:test/src

CFLAGS = -g -Iinclude -std=c++11
TESTCFLAGS = -g -Iinclude -Itest/include -std=c++11

incl = include/
src = src/
bin = bin/
test = test/

obj = argonaut.o JsonScanner.o Reader.o JsonToken.o JsonObject.o JsonValue.o JsonParser.o #SyntaxException.o
binobj = $(bin)argonaut.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)JsonToken.o $(bin)JsonObject.o $(bin)JsonValue.o $(bin)JsonParser.o #$(bin)SyntaxException.o
testobj = JsonScannerTests.o test.o JsonScanner.o Reader.o JsonToken.o BaseTests.o JsonParserTests.o \
		  JsonObject.o JsonValue.o JsonParser.o
testbinobj = $(bin)JsonScannerTests.o $(bin)test.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)JsonToken.o $(bin)BaseTests.o $(bin)JsonParser.o $(bin)JsonParserTests.o $(bin)JsonObject.o $(bin)JsonValue.o

argonaut : $(obj)
	g++ -o argonaut $(binobj)
argonaut.o : argonaut.cpp JsonScanner.o
	g++ $(CFLAGS) -c $(src)argonaut.cpp -o $(bin)argonaut.o
#SyntaxException.o : SyntaxException.h
#	g++ $(CFLAGS) -c $(incl)SyntaxException.h -o $(bin)SyntaxException.o
JsonParser.o : JsonParser.h JsonParser.cpp JsonScanner.o
	g++ $(CFLAGS) -c $(src)JsonParser.cpp -o $(bin)JsonParser.o
JsonScanner.o : JsonScanner.h JsonScanner.cpp Reader.o SyntaxException.h JsonToken.h JsonToken.o
	g++ $(CFLAGS) -c $(src)JsonScanner.cpp -o $(bin)JsonScanner.o
JsonObject.o : JsonObject.h JsonObject.cpp
	g++ $(CFLAGS) -c $(src)JsonObject.cpp -o $(bin)JsonObject.o
JsonToken.o : JsonToken.h JsonTypes.h JsonToken.cpp
	g++ $(CFLAGS) -c $(src)JsonToken.cpp -o $(bin)JsonToken.o
JsonValue.o : JsonValue.h JsonValue.cpp
	g++ $(CFLAGS) -c $(src)JsonValue.cpp -o $(bin)JsonValue.o
Reader.o : Reader.h Reader.cpp
	g++ $(CFLAGS) -c $(src)Reader.cpp -o $(bin)Reader.o
test : $(testobj)
	# TODO build all test classes and main test file
	g++ -o test_argonaut $(testbinobj)
test.o : test.cpp JsonScannerTests.o
	g++ $(TESTCFLAGS) -c $(test)src/test.cpp -o $(bin)test.o
BaseTests.o : BaseTests.h BaseTests.cpp
	g++ $(TESTCFLAGS) -c $(test)src/BaseTests.cpp -o $(bin)BaseTests.o
JsonParserTests.o : JsonParserTests.h JsonParserTests.cpp JsonParser.o BaseTests.o
	g++ $(TESTCFLAGS) -c $(test)src/JsonParserTests.cpp -o $(bin)JsonParserTests.o
JsonScannerTests.o : JsonScannerTests.h JsonScannerTests.cpp JsonScanner.o BaseTests.o
	g++ $(TESTCFLAGS) -c $(test)src/JsonScannerTests.cpp -o $(bin)JsonScannerTests.o
clean :
	rm -f bin/*.o argonaut test_argonaut
