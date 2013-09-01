#ifndef  JSONPARSER_H
#define  JSONPARSER_H
#include <string>
#include <istream>
#include <vector>
#include <memory>
#include "JsonScanner.h"
#include "JsonValue.h"

namespace Argonaut {
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
    std::unique_ptr<JsonObject> parseJson( std::string & json );
    std::unique_ptr<JsonObject> parseJson( std::istream * json );
protected:
    std::unique_ptr<JsonObject> parseJson( JsonScanner & scanner );
    void parseMembers( JsonScanner & scanner, 
            std::vector<JsonValue *> * members );
    JsonValue * parsePair( JsonScanner & scanner );
    void parseArray( JsonScanner & scanner, 
            std::vector<JsonValue *> * values );
    JsonValue * parseValue( JsonScanner & scanner, 
            const JsonToken & token, const std::string & name );
};
} // namespace Argonaut

#endif   /* ----- #ifndef JSONPARSER_H  ----- */
