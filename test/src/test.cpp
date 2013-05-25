#include <iostream>
#include <string>
#include "JsonScannerTests.h"

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
	bool end = true;
	std::string test = "test";
	JsonScannerTests jsonScannerTests( test );

	printResults( JsonScannerTests::IS_BLANK_OR_NEWLINE, jsonScannerTests.testIsBlankOrNewline(), false );
	std::string nine = "9";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, jsonScannerTests.testReturnIntegerToken( nine ), false );
	nine = "hey";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, !jsonScannerTests.testReturnIntegerToken( nine ), false );
	std::string brace = "{";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, jsonScannerTests.testReturnBraceToken( brace ), false );
	brace = "}";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, jsonScannerTests.testReturnBraceToken( brace ), false );
	brace = "not a brace";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, !jsonScannerTests.testReturnBraceToken( brace ), end );

	return 0;
}
