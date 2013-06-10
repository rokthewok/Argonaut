#ifndef  JSONPARSERTESTS_H
#define  JSONPARSERTESTS_H
#include <string>
#include "JsonParser.h"
#include "BaseTests.h"

/*
 * =====================================================================================
 *        Class:  JsonParserTests
 *  Description:  
 * =====================================================================================
 */
class JsonParserTests, public BaseTests, public JsonParser {
	public:
		JsonParserTests();                             /* constructor */
		virtual void runTests();
	private:
		bool testParseIntegerValue();
		bool testParsePair( std::string & json );
		bool testParseArray( std::string & json );
		bool testParseMembers( std::string & json );
		bool testParseJson( std::string & json );
}; /* -----  end of class JsonParserTests  ----- */

#endif   /* ----- #ifndef JSONPARSERTESTS_H  ----- */
