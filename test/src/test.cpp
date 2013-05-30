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
	
	std::string leadingBlanks = "\n    9";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, jsonScannerTests.testReturnIntegerToken( leadingBlanks ), false );
	std::string nine = "9";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, jsonScannerTests.testReturnIntegerToken( nine ), false );
	nine = "hey";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, !jsonScannerTests.testReturnIntegerToken( nine ), false );
	
	std::string brace = "{";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, jsonScannerTests.testReturnBraceToken( brace ), false );
	brace = "}";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, jsonScannerTests.testReturnBraceToken( brace ), false );
	brace = "not a brace";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, !jsonScannerTests.testReturnBraceToken( brace ), false );
	
	std::string boolean = "true";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, jsonScannerTests.testReturnBooleanToken( boolean ), false );
	boolean = "false";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, jsonScannerTests.testReturnBooleanToken( boolean ),  false );
	boolean = "ture";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, !jsonScannerTests.testReturnBooleanToken( boolean ), false );
	boolean = "flase";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, !jsonScannerTests.testReturnBooleanToken( boolean ), false );
	boolean = "oops";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, !jsonScannerTests.testReturnBooleanToken( boolean ), false );

	std::string null = "null";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, jsonScannerTests.testReturnNullToken( null ), false );
	null = "nul";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, !jsonScannerTests.testReturnNullToken( null ), false );
	null = "nil";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, !jsonScannerTests.testReturnNullToken( null ), false );
	null = "totally not null";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, !jsonScannerTests.testReturnNullToken( null ), false );

	std::string str = "\"this is my string.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, jsonScannerTests.testReturnStringToken( str ), false );
	str = "\"this is my \\t string.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, jsonScannerTests.testReturnStringToken( str ), false );
	str = "\"this is another \\b string \\n of \\\\ mine.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, jsonScannerTests.testReturnStringToken( str ), false );
	str = "\"this should be \\c invalid.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, !jsonScannerTests.testReturnStringToken( str ), end );
	
	return 0;
}
