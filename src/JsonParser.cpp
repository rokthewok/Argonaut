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

JsonParser::JsonParser() {

}

JsonObject * JsonParser::parseJson( std::string & json ) {
	JsonScanner * scanner = new JsonScanner( json );
	JsonObject * obj = parseJson( *scanner );

	delete scanner;
	
	return obj;
}

JsonObject * JsonParser::parseJson( std::istream * json ) {
	JsonScanner * scanner = new JsonScanner( json );
	JsonObject * obj = parseJson( *scanner );

	delete scanner;
	
	return obj;
}

JsonObject * JsonParser::parseJson( JsonScanner & scanner ) {
	JsonToken * token = scanner.getNextToken();

	std::vector<JsonValue *> * members = new std::vector<JsonValue *>();

	switch( token->getType() ) {
		case JsonTypes::OPEN_BRACE:
			delete token;
			parseMembers( scanner, members );
			return new JsonObject( members );
			break;
		default:
			delete token;
			// TODO throw syntax error
			return nullptr;
			break;
	}
}

void JsonParser::parseMembers( JsonScanner & scanner, std::vector<JsonValue *> * members ) {
	members->push_back( parsePair( scanner ) );

	JsonToken * token = scanner.getNextToken();
	switch( token->getType() ) {
		case JsonTypes::COMMA:
			delete token;
			parseMembers( scanner, members );
			break;
		case JsonTypes::CLOSE_BRACE:
			delete token;
			return;
		default:
			delete token;
			// TODO throw syntax error
			break;
	}
}

JsonValue * JsonParser::parsePair( JsonScanner & scanner ) {
	// 1. grab name
	// 2. grab colon
	// 3. grab value
	JsonToken * token = scanner.getNextToken();
	std::string name;
	switch( token->getType() ) {
		case JsonTypes::STRING:
			name = token->getToken();
			delete token;
			token = scanner.getNextToken();
			if( token->getType() == JsonTypes::COLON ) {
				delete token;
				token = scanner.getNextToken();
				return parseValue( scanner, token, name );
			} else {
				delete token;
				// TODO throw syntax error
			}
			break;
		default:
			// TODO throw syntax error
			break;
	}
}

void JsonParser::parseArray( JsonScanner & scanner, std::vector<JsonValue *> * values ) {
	static std::string name( "" );
	JsonToken * token = scanner.getNextToken();
	
	values->push_back( parseValue( scanner, token, name ) );

	token = scanner.getNextToken();
	if( token->getType() == JsonTypes::COMMA ) {
		delete token;
		parseArray( scanner, values );
	} else if ( token->getType() == JsonTypes::CLOSE_BRACKET ) {
		delete token;
	} else {
		delete token;
		// TODO throw syntax error
	}
}

JsonValue * JsonParser::parseValue( JsonScanner & scanner, JsonToken * token, std::string & name ) {
	int iValue;
	double rValue;
	bool bValue;
	std::vector<JsonValue *> * values;
	
	switch( token->getType() ) {
		case JsonTypes::INTEGER:
			iValue = atoi( token->getToken().c_str() );
			return new JsonValue( name, iValue );
			break;
		case JsonTypes::REAL:
			rValue = atof( token->getToken().c_str() );
			return new JsonValue( name, rValue );
			break;
		case JsonTypes::BOOLEAN:
			bValue = token->getToken() == "true" ? true : false;
			return new JsonValue( name, bValue );
			break;
		case JsonTypes::STRING:
			return new JsonValue( name, token->getToken() );
			break;
		case JsonTypes::OPEN_BRACKET:
			values = new std::vector<JsonValue *>();
			parseArray( scanner, values );
			break;
		case JsonTypes::NULLTYPE:
			break;
		case JsonTypes::OPEN_BRACE:
			break;
		default:
			// TODO throw semantic exception here
			break;
	}
}
