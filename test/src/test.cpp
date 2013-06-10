#include <iostream>
#include <string>
#include "JsonScannerTests.h"
#include "JsonParserTests.h"

void printResults( std::string testName, bool result, bool end ) {
	static unsigned int passed = 0;
	static unsigned int total = 0;

	if( result ) {
		std::cout << testName << ": pass" << std::endl;
		passed++;
	} else {
		std::cout << testName << ": fail" << std::endl;
	}

	total++;

	if( end ) {
		std::cout << passed << " of " << total << " tests passed." << std::endl;
	}
}

int main( int argc, char ** argv ) {
	std::string test = "test";
	JsonScannerTests jsonScannerTests( test );
	JsonParserTests jsonParserTests;

	jsonScannerTests.runTests();

	std::cout << std::endl;

	jsonParserTests.runTests();

	return 0;
}
