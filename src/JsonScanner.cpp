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
	JsonTypes type;
	ScannerState state = ScannerState::START;

	c = m_reader->getNextChar();
	if( c == '\0' ) {
		return jsonToken;
	}

	if( c == '{' || c == '}' ) {
		token.push_back( c );
		jsonToken = new JsonToken( JsonTypes::BRACE, token );
		return jsonToken; 
	} else if( isdigit( c ) || c == '-' || c == '.' ) {
		if( c == '.' ) {
			state = ScannerState::REAL;
			type = JsonTypes::REAL;
		} else {
			state = ScannerState::INTEGER;
			type = JsonTypes::INTEGER;
		}
		token.push_back( c );
		
		return readNumberToken( state, type, token );
	} else {
		return jsonToken;
	}
}

JsonToken * JsonScanner::readNumberToken( ScannerState state, JsonTypes type, std::string & token ) {
	char c;
	
	while( true ) {
		c = m_reader->getNextChar();

		if( isBlankOrNewline( c ) || c == '\0' ) return new JsonToken( type, token );

		switch( state ) {
		case ScannerState::INTEGER:
			if( isdigit( c ) ) {
				token.push_back( c );
			} else if( c == '.' ) {
				state = ScannerState::REAL;
				type = JsonTypes::REAL;
				token.push_back( c );
			} else {
				// TODO throw syntax error here
				return nullptr;
			}
			break;
		case ScannerState::REAL:
			if( isdigit( c ) ) {
				token.push_back( c );
			} else {
				// TODO throw syntax error here
				return nullptr;
			}
			break;
		default:
			return nullptr;
		};
	}
}

JsonToken * JsonScanner::readStringToken( std::string & token ) {
	char c;
	JsonTypes type = JsonTypes::STRING;

	while( true ) {
		if( isBlankOrNewline( c ) || c == '\0' ) return new JsonToken( type, token );

		
	}
}

JsonToken * JsonScanner::readBooleanToken( std::string & token ) {

}

JsonToken * JsonScanner::readNullToken( std::string & token ) {

}

bool JsonScanner::isBlankOrNewline( char c ) {
	static std::string characters( "\n\r\t " );
	return characters.find( c ) != std::string::npos ? true : false;
}
