#include <string>
#include <iostream>
#include <stdexcept>
#include "JsonScannerTests.h"

JsonScannerTests::JsonScannerTests( std::string & test ) 
	: JsonScanner( test ) {

}

void JsonScannerTests::runTests() {
	bool end = true;
	

	printResults( JsonScannerTests::IS_BLANK_OR_NEWLINE, testIsBlankOrNewline(), false );
	
	std::string leadingBlanks = "\n    9";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, testReturnIntegerToken( leadingBlanks ), false );
	std::string nine = "9";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, testReturnIntegerToken( nine ), false );
	nine = "hey";
	printResults( JsonScannerTests::RETURN_INTEGER_TOKEN, !testReturnIntegerToken( nine ), false );
	
	std::string brace = "{";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, testReturnBraceToken( brace ), false );
	brace = "}";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, testReturnBraceToken( brace ), false );
	brace = "not a brace";
	printResults( JsonScannerTests::RETURN_BRACE_TOKEN, !testReturnBraceToken( brace ), false );
	
	std::string boolean = "true";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, testReturnBooleanToken( boolean ), false );
	boolean = "false";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, testReturnBooleanToken( boolean ),  false );
	boolean = "ture";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, !testReturnBooleanToken( boolean ), false );
	boolean = "flase";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, !testReturnBooleanToken( boolean ), false );
	boolean = "oops";
	printResults( JsonScannerTests::RETURN_BOOLEAN_TOKEN, !testReturnBooleanToken( boolean ), false );

	std::string null = "null";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, testReturnNullToken( null ), false );
	null = "nul";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, !testReturnNullToken( null ), false );
	null = "nil";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, !testReturnNullToken( null ), false );
	null = "totally not null";
	printResults( JsonScannerTests::RETURN_NULL_TOKEN, !testReturnNullToken( null ), false );

	std::string str = "\"this is my string.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, testReturnStringToken( str ), false );
	str = "\"this is my \\t string.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, testReturnStringToken( str ), false );
	str = "\"this is another \\b string \\n of \\\\ mine.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, testReturnStringToken( str ), false );
	str = "\"this should be \\c invalid.\"";
	printResults( JsonScannerTests::RETURN_STRING_TOKEN, !testReturnStringToken( str ), false );

	printResults( JsonScannerTests::THROW_SYNTAX_EXCEPTION, testThrowSyntaxException(), end );
}

bool JsonScannerTests::testIsBlankOrNewline() {
	if( !this->isBlankOrNewline( ' ' ) ) return false;
	if( this->isBlankOrNewline( 'c' ) ) return false;
	if( !this->isBlankOrNewline( '\n' ) ) return false;
	if( !this->isBlankOrNewline( '\t' ) ) return false;
	if( !this->isBlankOrNewline( '\r' ) ) return false;
	return true;
}

bool JsonScannerTests::testReturnIntegerToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token; 

	bool result = false;
	
	try {
		token = m_scanner->getNextToken();
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
		return false;
	}

	if( token != nullptr && token->getType() == JsonTypes::INTEGER ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnBraceToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token;

	bool result = false;

	try {
		token = m_scanner->getNextToken();
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
		return false;
	}

	if( token != nullptr && 
			( token->getType() == JsonTypes::OPEN_BRACE || token->getType() == JsonTypes::CLOSE_BRACE ) ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnBooleanToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token;

	bool result = false;

	try {
		token = m_scanner->getNextToken();
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
		return false;
	}

	if( token != nullptr && token->getType() == JsonTypes::BOOLEAN ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnNullToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token;

	bool result = false;

	try {
		token = m_scanner->getNextToken();
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
		return false;
	}
	
	if( token != nullptr && token->getType() == JsonTypes::NULLTYPE ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnStringToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token;

	bool result = false;

	try {
		token = m_scanner->getNextToken();
	} catch ( std::exception & e ) {
		std::cout << e.what() << std::endl;
		return false;
	}

	if( token != nullptr && token->getType() == JsonTypes::STRING ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testThrowSyntaxException() {
	std::string json( "c" );
	JsonToken * token;
	m_scanner = new JsonScanner( json );
	bool exceptionThrown = false;

	try {
		token = m_scanner->getNextToken();
	} catch( std::exception & e ) {
		std::cout << e.what() << std::endl;
		exceptionThrown = true;
	}
	
	return exceptionThrown;
}

const std::string JsonScannerTests::IS_BLANK_OR_NEWLINE = "isBlankOrNewline";
const std::string JsonScannerTests::RETURN_INTEGER_TOKEN = "returnIntegerToken";
const std::string JsonScannerTests::RETURN_BRACE_TOKEN = "returnBraceToken";
const std::string JsonScannerTests::RETURN_BOOLEAN_TOKEN = "returnBooleanToken";
const std::string JsonScannerTests::RETURN_NULL_TOKEN = "returnNullToken";
const std::string JsonScannerTests::RETURN_STRING_TOKEN = "returnStringToken";
const std::string JsonScannerTests::THROW_SYNTAX_EXCEPTION = "throwSyntaxException";
