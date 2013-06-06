#ifndef  JSONPARSER_H
#define  JSONPARSER_H
#include <string>
#include <istream>
#include "JsonScanner.h"

class JsonObject;
/*
 * =====================================================================================
 *        Class:  JsonParser
 *  Description:  
 * =====================================================================================
 */
class JsonParser {
	public:
		JsonParser();
		~JsonParser();
		JsonObject * parseJson( const std::string & json );
		JsonObject * parseJson( const std::istream & json );
	private:
		JsonObject * parseJson( JsonScanner & scanner );
		JsonValue * parseValue( JsonScanner & scanner, JsonToken * token );
};

#endif   /* ----- #ifndef JSONPARSER_H  ----- */
