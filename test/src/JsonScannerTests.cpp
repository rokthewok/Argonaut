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
		bool result = true;
	}

	if( token != nullptr ) delete token;
	delete m_scanner;

	return result;
}

const std::string JsonScannerTests::IS_BLANK_OR_NEWLINE = "isBlankOrNewline";
const std::string JsonScannerTests::RETURN_INTEGER_TOKEN = "returnIntegerToken";
