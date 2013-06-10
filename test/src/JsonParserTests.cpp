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
#include "JsonParserTests.h"
#include "JsonValue.h"
#include "JsonScanner.h"

JsonParserTests::JsonParserTests() {

}

void JsonParserTests::runTests() {
	bool end = true;

	printResults( JsonParserTests::PARSE_INTEGER_VALUE, testParseIntegerValue(), false );
	printResults( JsonParserTests::PARSE_REAL_VALUE, testParseRealValue(), false );
	printResults( JsonParserTests::PARSE_BOOLEAN_VALUE, testParseBooleanValue(), end );
}

bool JsonParserTests::testParseIntegerValue() {
	std::string json( "-907" );
	JsonScanner scanner( json );
	std::string name( "testing_value" );
	
	JsonToken * token = scanner.getNextToken();
	JsonValue * value = this->parseValue( scanner, token, name );
	
	delete token;
	if( value->isInteger() && value->getInteger() == atoi( json.c_str() ) ) {
		delete value;
		return true;
	} else {
		delete value;
		return false;
	}
}

bool JsonParserTests::testParseRealValue() {
	std::string json( "-907.55" );
	JsonScanner scanner( json );
	std::string name( "testing_value" );
	
	JsonToken * token = scanner.getNextToken();
	JsonValue * value = this->parseValue( scanner, token, name );
	
	delete token;
	if( value->isReal() && value->getReal() == atof( json.c_str() ) ) {
		delete value;
		return true;
	} else {
		delete value;
		return false;
	}
}

bool JsonParserTests::testParseBooleanValue() {
	std::string json( "true" );
	JsonScanner scanner( json );
	std::string name( "testing_value" );
	
	JsonToken * token = scanner.getNextToken();
	JsonValue * value = this->parseValue( scanner, token, name );
	
	bool result = false;
	if( value->isBoolean() && value->getBoolean() ) {
		json = "false";
		JsonScanner scannerTwo( json );
		
		delete token;
		delete value;
		token = scannerTwo.getNextToken();
		value = parseValue( scanner, token, name );
		if( value->isBoolean() && !value->getBoolean() ) {
			result = true;
		}
	}

	delete token;
	delete value;

	return result;
}

bool JsonParserTests::testParseStringValue() {

}

bool JsonParserTests::testParsePair( std::string & json ) {

}

bool JsonParserTests::testParseArray( std::string & json ) {

}

bool JsonParserTests::testParseMembers( std::string & json ) {
	
}

bool JsonParserTests::testParseJson( std::string & json ) {
	
}

const std::string JsonParserTests::PARSE_INTEGER_VALUE = "parseIntegerValue";
const std::string JsonParserTests::PARSE_REAL_VALUE = "parseRealValue";
const std::string JsonParserTests::PARSE_BOOLEAN_VALUE = "parseBooleanValue";
const std::string JsonParserTests::PARSE_STRING_VALUE = "parseStringValue";
