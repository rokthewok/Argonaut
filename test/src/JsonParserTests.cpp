/*
 * =====================================================================================
 *
 *       Filename:  JsonParserTests.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/09/2013 07:30:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "JsonValue.h"
#include "JsonScanner.h"

JsonParserTests::JsonParserTests() {

}

virtual void JsonParserTests::runTests() {
	std::cout << "testParseIntegerValue: "; 
	if( testParseIntegerValue() ) {
		std::cout << true << std::endl;
	} else {
		std::cout << false << std::endl;
	}
}

bool JsonParserTests::testParseIntegerValue() {
	std::string json( "-907" );
	JsonScanner scanner( json );
	std::string name( "testing_value" );
	
	JsonToken * token = scanner.getNextToken();
	JsonValue * value = scanner.parseValue( scanner, token, name );
	
	delete token;
	if( value->isInteger() && value->getInteger() == atoi( json.c_str() ) ) {
		delete value;
		return true;
	} else {
		delete value;
		return false;
	}
}

bool JsonParserTests::testParsePair( std::string & json ) {

}

bool JsonParserTests::testParseArray( std::string & json ) {

}

bool JsonParserTests::testParseMembers( std::string & json ) {
	
}

bool JsonParserTests::testParseJson( std::string & json ) {
	
}
