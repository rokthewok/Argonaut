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
class JsonParserTests : private JsonParser, public BaseTests {
	public:
		JsonParserTests();                             /* constructor */
		virtual void runTests();
		
		static const std::string PARSE_INTEGER_VALUE;
		static const std::string PARSE_REAL_VALUE;
		static const std::string PARSE_BOOLEAN_VALUE;
		static const std::string PARSE_STRING_VALUE;
		static const std::string PARSE_PAIR;
	private:
		bool testParseIntegerValue();
		bool testParseRealValue();
		bool testParseBooleanValue();
		bool testParseStringValue();
		bool testParsePair();
		bool testParseArray( std::string & json );
		bool testParseMembers( std::string & json );
		bool testParseJson( std::string & json );

}; /* -----  end of class JsonParserTests  ----- */

#endif   /* ----- #ifndef JSONPARSERTESTS_H  ----- */
