#include <cctype>
#include "JsonScanner.h"
#include "JsonTypes.h"
#include "JsonToken.h"
#include "SyntaxException.h"
#include "NumberFormatException.h"
#include "BooleanFormatException.h"
#include "NullFormatException.h"
#include "StringFormatException.h"

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
	while ( isBlankOrNewline( c ) ) {
		c = m_reader->getNextChar();
	}

	if( c == '\0' ) {
		return jsonToken;
	}

	if( c == '{' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::OPEN_BRACE, token );
	} else if( c == '}' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::CLOSE_BRACE, token );
	} else if( c == '[' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::OPEN_BRACKET, token );
	} else if( c == ']' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::CLOSE_BRACKET, token );
	} else if( c == ',' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::COMMA, token );
	} else if( c == ':' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::COLON, token );
	} else if( isdigit( c ) || c == '-' || c == '.' ) {
		if( c == '.' ) {
			state = ScannerState::REAL;
			type = JsonTypes::REAL;
		} else {
			state = ScannerState::INTEGER;
			type = JsonTypes::INTEGER;
		}
		token.push_back( c );
		try {	
			return readNumberToken( state, type, token );
		} catch( NumberFormatException e ) {
			throw e;
		}
	} else if( c == 't' || c == 'f' ) {
		token.push_back( c );
		try {	
			return readBooleanToken( token );
		} catch( BooleanFormatException e ) {
			throw e;
		}
	} else if( c == '\"' ) {
		try {	
			return readStringToken( token );
		} catch( StringFormatException e ) {
			throw e;
		}
	} else if( c == 'n' ) {
		token.push_back( c );
		try {	
			return readNullToken( token );
		} catch( NullFormatException e ) {
			throw e;
		}
	} else {
		throw SyntaxException( "error in JsonScanner" );
	}
}

JsonToken * JsonScanner::readNumberToken( ScannerState state, JsonTypes type, std::string & token ) {
	char c;
	
	while( true ) {
		c = m_reader->peekNextChar();

		if( isBlankOrNewline( c ) || c == '\0' || c == ',' ) {
			return new JsonToken( type, token );
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
				// TODO throw syntax error here
				throw NumberFormatException();
				//return nullptr;
			}
			break;
		case ScannerState::REAL:
			if( isdigit( c ) ) {
				token.push_back( c );
			} else {
				// TODO throw syntax error here
				throw NumberFormatException();
				//return nullptr;
			}
			break;
		default:
			throw NumberFormatException();
			//return nullptr;
		};
	}
}

JsonToken * JsonScanner::readStringToken( std::string & token ) {
	char c;
	JsonTypes type = JsonTypes::STRING;
	ScannerState state = ScannerState::STRING;
	while( true ) {
		c = m_reader->getNextChar();
		switch ( state ) {
			case ScannerState::STRING:
				if( c == '\"' ) {
					return new JsonToken( type, token );
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
					//return nullptr;
				}
				break;
			default:
				throw StringFormatException();
				//return nullptr;
				break;
		}
	}
}

JsonToken * JsonScanner::readBooleanToken( std::string & token ) { char c;
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
					else return new JsonToken( type, token );
				} else {
					throw BooleanFormatException();
					//return nullptr;
				}
				break;
			case ScannerState::FALSE:
				if( c == next ) {
					token.push_back( c );
					if( next == 'a' ) next = 'l';
					else if( next == 'l' ) next = 's';
					else if( next == 's' ) next = 'e';
					else return new JsonToken( type, token );
				} else {
					throw BooleanFormatException();
					//return nullptr;
				}
				break;
			default:
				throw BooleanFormatException();
				//return nullptr;
				break;
		}
	}
}

JsonToken * JsonScanner::readNullToken( std::string & token ) {
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
			//return nullptr;
		}
	}

	c = m_reader->getNextChar();

	if( c == 'l' ) {
		token.push_back( c );
		return new JsonToken( JsonTypes::NULLTYPE, token );
	} else {
		throw NullFormatException();
		//return nullptr;
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
