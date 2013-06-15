#ifndef  JSONPARSERTESTS_H
#define  JSONPARSERTESTS_H
#include <string>
#include "JsonParser.h"
#include "BaseTests.h"
#include "JsonObject.h"

/*
 * =====================================================================================
 *        Class:  JsonParserTests
 *  Description:  
 * =====================================================================================
 */
class JsonParserTests : private JsonParser, public BaseTests {
	public:
		JsonParserTests();                             /* constructor */
		virtual void runTests();
		
		static const std::string PARSE_INTEGER_VALUE;
		static const std::string PARSE_REAL_VALUE;
		static const std::string PARSE_BOOLEAN_VALUE;
		static const std::string PARSE_STRING_VALUE;
		static const std::string PARSE_PAIR;
		static const std::string PARSE_MEMBERS;
		static const std::string PARSE_JSON;
		static const std::string PARSE_NESTED_JSON;
	private:
		bool testParseIntegerValue();
		bool testParseRealValue();
		bool testParseBooleanValue();
		bool testParseStringValue();
		bool testParsePair();
		bool testParseArray( std::string & json );
		bool testParseMembers();
		bool testParseJson();
		bool testParseNestedJson();

		bool checkValidPerson( JsonObject * object );
}; /* -----  end of class JsonParserTests  ----- */

#endif   /* ----- #ifndef JSONPARSERTESTS_H  ----- */
