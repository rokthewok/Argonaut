#include <string>
#include "JsonScannerTests.h"

JsonScannerTests::JsonScannerTests( std::string & test ) 
	: JsonScanner( test ) {

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
	JsonToken * token = m_scanner->getNextToken();

	bool result = false;
	if( token != nullptr && token->getType() == JsonTypes::INTEGER ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnBraceToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token = m_scanner->getNextToken();

	bool result = false;
	if( token != nullptr && token->getType() == JsonTypes::BRACE ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnBooleanToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token = m_scanner->getNextToken();

	bool result = false;
	if( token != nullptr && token->getType() == JsonTypes::BOOLEAN ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

bool JsonScannerTests::testReturnNullToken( std::string & testString ) {
	m_scanner = new JsonScanner( testString );
	JsonToken * token = m_scanner->getNextToken();

	bool result = false;
	if( token != nullptr && token->getType() == JsonTypes::NULLTYPE ) {
		result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

const std::string JsonScannerTests::IS_BLANK_OR_NEWLINE = "isBlankOrNewline";
const std::string JsonScannerTests::RETURN_INTEGER_TOKEN = "returnIntegerToken";
const std::string JsonScannerTests::RETURN_BRACE_TOKEN = "returnBraceToken";
const std::string JsonScannerTests::RETURN_BOOLEAN_TOKEN = "returnBooleanToken";
const std::string JsonScannerTests::RETURN_NULL_TOKEN = "returnNullToken";
const std::string JsonScannerTests::RETURN_STRING_TOKEN = "returnStringToken";
