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

}
