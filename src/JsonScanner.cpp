#include <cctype>
#include "JsonScanner.h"
#include "JsonTypes.h"
#include "JsonToken.h"

JsonScanner::JsonScanner( std::istream * in )
	: m_reader( new Reader( in ) ) {

}

JsonScanner::JsonScanner( std::string & str )
	: m_reader( new Reader( str ) ) {

}

JsonToken * JsonScanner::getNextToken() {
	char c;
	JsonToken * jsonToken = nullptr;
	std::string token;
	ScannerState state = ScannerState::START;

	c = m_reader->getNextChar();
	if( c == '\0' ) {
		return jsonToken;
	}

	if( c == '{' || c == '}' ) {
		token.push_back( c );
		jsonToken = new JsonToken( JsonTypes::BRACE, token );
		return jsonToken; 
	} else if( isdigit( c ) || c == '.' ) {
		if( c == '.' ) {
			state = ScannerState::REAL;
		} else {
			state = ScannerState::INTEGER;
		}
		token.push_back( c );

		c = m_reader->getNextChar();
		while( true ) {
			c = m_reader->getNextChar();

			if( isBlankOrNewline( c ) ) return jsonToken;

			switch( state ) {
			case ScannerState::INTEGER:
				if( isdigit( c ) ) {
					token.push_back( c );
				} else if( c == '.' ) {
					state = ScannerState::REAL;
					token.push_back( c );
				} else {
					// TODO throw syntax error here
					return jsonToken;
				}
				break;
			case ScannerState::REAL:
				if( isdigit( c ) ) {
					token.push_back( c );
				} else {
					// TODO throw syntax error here
					return jsonToken;
				}
				break;
			default:
				return jsonToken;
			};
		}
	}
}

void JsonScanner::readToken( JsonToken * jsonToken, std::string & token ) {
	while( true ) {
			
	}
}

bool JsonScanner::isBlankOrNewline( char c ) {
	static std::string characters( "\n\r\t " );
	return characters.find( c ) != std::string::npos ? true : false;
}
