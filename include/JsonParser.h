#ifndef  JSONPARSER_H
#define  JSONPARSER_H
#include <string>
#include <istream>
#include <vector>
#include "JsonScanner.h"

class JsonObject;
class JsonValue;
class JsonToken;
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
		void parseMembers( JsonScanner & scanner, std::vector<JsonValue *> * members );
		JsonValue * parsePair( JsonScanner & scanner );
		void parseArray( JsonScanner & scanner, std::vector<JsonValue *> * values );
		JsonValue * parseValue( JsonScanner & scanner, JsonToken * token, std::string name );
};

#endif   /* ----- #ifndef JSONPARSER_H  ----- */
