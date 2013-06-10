#ifndef  JSONPARSER_H
#define  JSONPARSER_H
#include <string>
#include <istream>
#include <vector>
#include "JsonScanner.h"
#include "JsonValue.h"

class JsonObject;
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
		JsonObject * parseJson( std::string & json );
		JsonObject * parseJson( std::istream * json );
	protected:
		JsonObject * parseJson( JsonScanner & scanner );
		void parseMembers( JsonScanner & scanner, std::vector<JsonValue *> * members );
		JsonValue * parsePair( JsonScanner & scanner );
		void parseArray( JsonScanner & scanner, std::vector<JsonValue *> * values );
		JsonValue * parseValue( JsonScanner & scanner, JsonToken * token, std::string & name );
	private:
};

#endif   /* ----- #ifndef JSONPARSER_H  ----- */
