#include <cctype>
#include "JsonScanner.h"
#include "JsonTypes.h"
//#include "SyntaxException.h"

JsonScanner::JsonScanner( std::istream * in )
	: m_reader( new Reader( in ) ) {

}

JsonScanner::JsonScanner( std::string & str )
	: m_reader( new Reader( str ) ) {

}

std::string JsonScanner::getNextToken() {
	char c;
	std::string token;
	ScannerState state = ScannerState::START;

	c = m_reader->getNextChar();
	if( c == '\0' ) {
		return token;
	}

	if( c == '{' || c == '}' ) {
		token.push_back( c );
		return token;
	} else if( isdigit( c ) || c == '.' ) {
		if( c == '.' ) {
			state = ScannerState::REAL;
		} else {
			state = ScannerState::INTEGER;
		}
		token.push_back( c );

		c = m_reader->getNextChar();
		while( true ) {
			if( isdigit( c ) ) {
				token.push_back( c );
			} else if( c == '.' ) {
				token.push_back( c );
			}
		}
	}
}
