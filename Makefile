# Argonaut C++ Makefile
VPATH = src:include:test/include:test/src

CFLAGS = -g -Iinclude -std=c++11
TESTCFLAGS = -g -Iinclude -Itest/include -std=c++11

incl = include/
src = src/
bin = bin/
test = test/

obj = main.o JsonScanner.o Reader.o JsonToken.o JsonObject.o JsonValue.o JsonParser.o SyntaxException.h \
		BooleanFormatException.h NumberFormatException.h NullFormatException.h StringFormatException.h \
		ValueParsingException.h PairParsingException.h ArrayParsingException.h MemberParsingException.h JsonParsingException.h Argonaut.o
binobj = $(bin)main.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)JsonToken.o $(bin)JsonObject.o $(bin)JsonValue.o $(bin)JsonParser.o $(bin)Argonaut.o
testobj = JsonScannerTests.o test.o JsonScanner.o Reader.o JsonToken.o BaseTests.o JsonParserTests.o \
		  JsonObject.o JsonValue.o JsonParser.o
testbinobj = $(bin)JsonScannerTests.o $(bin)test.o $(bin)JsonScanner.o $(bin)Reader.o $(bin)JsonToken.o $(bin)BaseTests.o $(bin)JsonParser.o $(bin)JsonParserTests.o $(bin)JsonObject.o $(bin)JsonValue.o

$(shell mkdir bin/)

argonaut : $(obj)
	g++ -o argonaut $(binobj) $(incl)SyntaxException.h
main.o : main.cpp Argonaut.o
	g++ $(CFLAGS) -c $(src)main.cpp -o $(bin)main.o
Argonaut.o : Argonaut.h Argonaut.cpp JsonParser.o
	g++ $(CFLAGS) -c $(src)Argonaut.cpp -o $(bin)Argonaut.o
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
	rm -rf bin/ argonaut test_argonaut
