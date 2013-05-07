#include <string>
#include "JsonScannerTests.h"

JsonScannerTests::JsonScannerTests( std::string & testString )
	: JsonScanner( testString ) {

}

bool JsonScannerTests::testIsBlankOrNewline() {
	if( !this->isBlankOrNewline( ' ' ) ) return false;
	if( this->isBlankOrNewline( 'c' ) ) return false;
	if( !this->isBlankOrNewline( '\n' ) ) return false;
	if( !this->isBlankOrNewline( '\t' ) ) return false;
	if( !this->isBlankOrNewline( '\r' ) ) return false;
	return true;
}

const std::string JsonScannerTests::IsBlankOrNewline = "isBlankOrNewline";
