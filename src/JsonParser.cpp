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

JsonObject * JsonParser::parseJson( std::istream & json ) {
	JsonScanner * scanner = new JsonScanner( json );
	JsonObject * obj = parseJson( *scanner );

	delete scanner;
	
	return obj;
}

JsonObject * JsonParser::parseJson( JsonScanner & scanner ) {
	JsonToken * token = scanner.getNextToken();


}

JsonValue * JsonParser::parseValue( JsonScanner & scanner, JsonToken * token ) {
	switch( token->getType() ) {
		case JsonTypes::INTEGER:
			int value = atoi( token->getValue().c_str() );
			return new JsonValue( m_name, value );
			break;
		case JsonTypes::REAL:
			break;
		case JsonTypes::BOOLEAN:
			break;
		case JsonTypes::STRING:
			break;
		case JsonTypes::ARRAY:
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
