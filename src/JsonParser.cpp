/*
 * =====================================================================================
 *
 *       Filename:  JsonParser.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2013 12:51:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "JsonParser.h"
#include "JsonObject.h"
#include "JsonToken.h"
#include "JsonTypes.h"
#include "ValueParsingException.h"
#include "PairParsingException.h"
#include "ArrayParsingException.h"
#include "MemberParsingException.h"
#include "JsonParsingException.h"

namespace Argonaut {
JsonParser::JsonParser() {

}

std::unique_ptr<JsonObject> JsonParser::parseJson( std::string & json ) {
	JsonScanner scanner( json );
	std::unique_ptr<JsonObject> obj;
	try {
 		obj = parseJson( scanner );
	}
	catch ( const std::exception & e ) {
		throw;
	}
	
	return obj;
}

std::unique_ptr<JsonObject> JsonParser::parseJson( std::istream * json ) {
	JsonScanner scanner( json );
	std::unique_ptr<JsonObject> obj;
	try {
 		obj = parseJson( scanner );
	}
	catch ( const std::exception & e ) {
		throw;
	}
	
	return obj;
}

std::unique_ptr<JsonObject> JsonParser::parseJson( JsonScanner & scanner ) {
	JsonToken token;
	try {
		token = scanner.getNextToken();
	}
	catch ( const std::exception & e ) {
		throw;
	}

	std::vector<JsonValue *> * members = new std::vector<JsonValue *>();

	switch( token.getType() ) {
	case JsonTypes::OPEN_BRACE:
		try {
			parseMembers( scanner, members );
		}
		catch ( const std::exception & e ) {
			delete members;
			throw;
		}
		return std::unique_ptr<JsonObject>( new JsonObject( members ) );
		break;
	default:
		delete members;
		throw JsonParsingException();
		break;
	}
}

void JsonParser::parseMembers( JsonScanner & scanner, std::vector<JsonValue *> * members ) {
	JsonValue * value;

	try {
		value = parsePair( scanner );
	}
	catch ( const std::exception & e ) {
		throw;
	}

	members->push_back( value );

	JsonToken token;
	try {
 		token = scanner.getNextToken();
	}
	catch ( const std::exception & e ) {
		throw;
	}

	switch( token.getType() ) {
		case JsonTypes::COMMA:
			try {
				parseMembers( scanner, members );
			}
			catch ( const std::exception & e ) {
				throw;
			}
			break;
		case JsonTypes::CLOSE_BRACE:
			return;
		default:
			throw MemberParsingException();
			break;
	}
}

JsonValue * JsonParser::parsePair( JsonScanner & scanner ) {
	// 1. grab name
	// 2. grab colon
	// 3. grab value
	JsonToken token;
	try {
		token = scanner.getNextToken();
	}
	catch ( const std::exception & e ) {
		throw;
	}

	std::string name;
	JsonValue * value;
	switch( token.getType() ) {
		case JsonTypes::STRING:
			name = token.getToken();
			token = scanner.getNextToken();

			if( token.getType() == JsonTypes::COLON ) {
				try {
					token = scanner.getNextToken();
				} catch( const std::exception & e ) {
					throw;
				}

				try {
					value = parseValue( scanner, token, name );
				}
				catch ( const std::exception & e ) {
					throw;
				}
				return value;
			} else {
				throw PairParsingException();
			}
			break;
		default:
			throw PairParsingException();
			break;
	}
}

void JsonParser::parseArray( JsonScanner & scanner, std::vector<JsonValue *> * values ) {
	static std::string name( "" );
	JsonToken token;
	try {
		token = scanner.getNextToken();
	}
	catch ( const std::exception & e ) {
		throw;
	}

	JsonValue * value;
	try {
		value = parseValue( scanner, token, name );
	} catch( const std::exception & e ) {
		throw;
	}
	values->push_back( value );
	try {
		token = scanner.getNextToken();
	} catch( const std::exception & e ) {
		throw;
	}
	if( token.getType() == JsonTypes::COMMA ) {
		try {
			parseArray( scanner, values );
		} catch( std::exception & e ) {
			throw;
		}
	} else if ( token.getType() == JsonTypes::CLOSE_BRACKET ) {
	} else {
		throw ArrayParsingException();
	}
}

JsonValue * JsonParser::parseValue( JsonScanner & scanner, 
		const JsonToken & token, const std::string & name ) {
	int iValue;
	double rValue;
	bool bValue;
	std::vector<JsonValue *> * values;
	std::vector<JsonValue *> * members;

	switch( token.getType() ) {
		case JsonTypes::INTEGER:
			iValue = atoi( token.getToken().c_str() );
			return new JsonValue( name, iValue );
			break;
		case JsonTypes::REAL:
			rValue = atof( token.getToken().c_str() );
			return new JsonValue( name, rValue );
			break;
		case JsonTypes::BOOLEAN:
			bValue = token.getToken() == "true" ? true : false;
			return new JsonValue( name, bValue );
			break;
		case JsonTypes::STRING:
			return new JsonValue( name, token.getToken() );
			break;
		case JsonTypes::OPEN_BRACKET:
			values = new std::vector<JsonValue *>();
			try {
				parseArray( scanner, values );
			} catch( const std::exception & e ) {
				delete values;
				throw;
			}
			return new JsonValue( name, values );
			break;
		case JsonTypes::NULLTYPE:
			break;
		case JsonTypes::OPEN_BRACE:
			members = new std::vector<JsonValue *>();
			try {
				parseMembers( scanner, members );
			} catch( const std::exception & e ) {
				delete members;
				throw;
			}
			return new JsonValue( name, new JsonObject( members ) );
			break;
		default:
			throw ValueParsingException();
			break;
	}
}
} // namespace Argonaut
