#include <cctype>
#include "JsonScanner.h"
#include "JsonTypes.h"
#include "JsonToken.h"
#include "SyntaxException.h"
#include "NumberFormatException.h"
#include "BooleanFormatException.h"
#include "NullFormatException.h"
#include "StringFormatException.h"

namespace Argonaut {
JsonScanner::JsonScanner( std::istream * in )
	: m_reader( new Reader( in ) ) {

}

JsonScanner::JsonScanner( const std::string & str )
	: m_reader( new Reader( str ) ) {

}

JsonScanner::~JsonScanner() {
	delete m_reader;
}

JsonToken JsonScanner::getNextToken() {
	char c;
	std::string token;
	JsonTypes type;
	ScannerState state = ScannerState::START;

	c = m_reader->getNextChar();
	while ( isBlankOrNewline( c ) ) {
		c = m_reader->getNextChar();
	}

	if( c == '\0' ) {
		return JsonToken( JsonTypes::END_OF_STREAM, token );
	}

	if( c == '{' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::OPEN_BRACE, token );
	} else if( c == '}' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::CLOSE_BRACE, token );
	} else if( c == '[' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::OPEN_BRACKET, token );
	} else if( c == ']' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::CLOSE_BRACKET, token );
	} else if( c == ',' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::COMMA, token );
	} else if( c == ':' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::COLON, token );
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
	} else if( c == 't' || c == 'f' ) {
		token.push_back( c );
        return readBooleanToken( token );
	} else if( c == '\"' ) {
        return readStringToken( token );
	} else if( c == 'n' ) {
		token.push_back( c );
        return readNullToken( token );
	} else {
		throw SyntaxException( "error in JsonScanner" );
	}
}

JsonToken JsonScanner::readNumberToken( ScannerState state, JsonTypes type, std::string & token ) {
	char c;
	
	while( true ) {
		c = m_reader->peekNextChar();

		if( isBlankOrNewline( c ) || c == '\0' || c == ',' ) {
			return JsonToken( type, token );
		} else {
			c = m_reader->getNextChar();
		}

		switch( state ) {
		case ScannerState::INTEGER:
			if( isdigit( c ) ) {
				token.push_back( c );
			} else if( c == '.' ) {
				state = ScannerState::REAL;
				type = JsonTypes::REAL;
				token.push_back( c );
			} else {
				throw NumberFormatException();
			}
			break;
		case ScannerState::REAL:
			if( isdigit( c ) ) {
				token.push_back( c );
			} else {
				throw NumberFormatException();
			}
			break;
		default:
			throw NumberFormatException();
		};
	}
}

JsonToken JsonScanner::readStringToken( std::string & token ) {
	char c;
	JsonTypes type = JsonTypes::STRING;
	ScannerState state = ScannerState::STRING;

    c = m_reader->getNextChar();
    if( c == '\0' ) throw StringFormatException();

	while( true ) {
		switch ( state ) {
        case ScannerState::STRING:
            if( c == '\"' ) {
                return JsonToken( type, token );
            } else if( c == '\\' ) {
                state = ScannerState::SP_CHAR;
                token.push_back( c );
            } else {
                token.push_back( c );
            }
            break;
        case ScannerState::SP_CHAR:
            if( isSpecialChar( c ) ) {
                token.push_back( c );
                state = ScannerState::STRING;
            } else {
                throw StringFormatException();
            }
            break;
        default:
            throw StringFormatException();
            break;
		}
		c = m_reader->getNextChar();
	}
}

JsonToken JsonScanner::readBooleanToken( std::string & token ) { char c;
	char next = token == "t" ? 'r' : 'a';
	JsonTypes type = JsonTypes::BOOLEAN;
	ScannerState state = token == "t" ? ScannerState::TRUE : ScannerState::FALSE;

	while( true ) {
		c = m_reader->getNextChar();

		switch ( state ) {
		case ScannerState::TRUE:
			if( c == next ) {
				token.push_back( c );
				if( next == 'r' ) next = 'u';
				else if( next == 'u' ) next = 'e';
				else return JsonToken( type, token );
			} else {
				throw BooleanFormatException();
			}
			break;
		case ScannerState::FALSE:
			if( c == next ) {
				token.push_back( c );
				if( next == 'a' ) next = 'l';
				else if( next == 'l' ) next = 's';
				else if( next == 's' ) next = 'e';
				else return JsonToken( type, token );
			} else {
				throw BooleanFormatException();
			}
			break;
		default:
			throw BooleanFormatException();
			break;
		}
	}
}

JsonToken JsonScanner::readNullToken( std::string & token ) {
	char c;
	char next = 'u';

	while( true ) {
		c = m_reader->getNextChar();

		if( c == next ) {
			token.push_back( c );
			if( next == 'u' ) next = 'l';
			else if( next == 'l' ) break;
		} else {
			throw NullFormatException();
		}
	}

	c = m_reader->getNextChar();

	if( c == 'l' ) {
		token.push_back( c );
		return JsonToken( JsonTypes::NULLTYPE, token );
	} else {
		throw NullFormatException();
	}
}

bool JsonScanner::isBlankOrNewline( char c ) {
	static std::string characters( "\n\r\t " );
	return characters.find( c ) != std::string::npos ? true : false;
}

bool JsonScanner::isSpecialChar( char c ) {
	static std::string characters( "\"\\/bfnrtu" );
	return characters.find( c ) != std::string::npos ? true : false;
}
} // namespace Argonaut
