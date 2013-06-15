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
#include "JsonObject.h"

JsonParserTests::JsonParserTests() {

}

void JsonParserTests::runTests() {
	bool end = true;

	printResults( JsonParserTests::PARSE_INTEGER_VALUE, testParseIntegerValue(), false );
	printResults( JsonParserTests::PARSE_REAL_VALUE, testParseRealValue(), false );
	printResults( JsonParserTests::PARSE_BOOLEAN_VALUE, testParseBooleanValue(), false );
	printResults( JsonParserTests::PARSE_PAIR, testParsePair(), false );
	printResults( JsonParserTests::PARSE_MEMBERS, testParseMembers(), false );
	printResults( JsonParserTests::PARSE_JSON, testParseJson(), false );
	printResults( JsonParserTests::PARSE_NESTED_JSON, testParseNestedJson(), end );
}

bool JsonParserTests::testParseIntegerValue() {
	std::string json( "-907" );
	JsonScanner scanner( json );
	std::string name( "testing_value" );
	
	JsonToken * token = scanner.getNextToken();
	JsonValue * value = parseValue( scanner, token, name );
	
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
	JsonValue * value = parseValue( scanner, token, name );
	
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

bool JsonParserTests::testParsePair() {
	std::string json( "\"number\" : 98" );
	JsonScanner scanner( json );
	
	JsonValue * value = parsePair( scanner );
	
	if( value->isInteger() && value->getInteger() == 98 && value->getName() == "number" ) {
		delete value;
		return true;
	} else {
		delete value;
		return false;
	}
}

bool JsonParserTests::testParseArray( std::string & json ) {

}

bool JsonParserTests::testParseMembers() {
	std::string json( "\"greeting\" : \"Hello world!\" , \"number\" : 93 , \"valid\" : true }" );
	JsonScanner scanner( json );

	std::vector<JsonValue *> * members = new std::vector<JsonValue *>();

	parseMembers( scanner, members );

	bool greetingFound = false;
	bool numberFound = false;
	bool validFound = false;
	for( auto value : *members ) {
		if( value->isString() && value->getString() == "Hello world!" && value->getName() == "greeting" ) {
			greetingFound = true;
		} else if( value->isInteger() && value->getName() == "number" && value->getInteger() == 93 ) {
			numberFound = true;
		} else if( value->isBoolean() && value->getName() == "valid" && value->getBoolean() == true ) { 
			validFound = true;
		}
	}

	delete members;

	if( greetingFound && numberFound && validFound ) {
		return true;
	} else {
		return false;
	}
}

bool JsonParserTests::testParseJson() {
	std::string json( "{ \"name\" : \"John Ruffer\",\n\"age\" : 23, \"height\" : 172.7 , \"vegan\" : false \n}" );
	JsonScanner scanner( json );

	JsonObject * object = parseJson( scanner );

	bool result = checkValidPerson( object );

	delete object;

	return result;
}

bool JsonParserTests::testParseNestedJson() {
	std::string json( "{ \"links\" : [ \"http://eightbitheart.blogspot.com/\",\"http://eightbitheart.tumblr.com/\" ] ,"
						" \"person\" : { \"name\" : \"John Ruffer\",\n\"age\" : 23, \"height\" : 172.7 , \"vegan\" : false \n} }" );
	JsonScanner scanner( json );

	JsonObject * object = parseJson( scanner );

	auto members = object->getMembers();

	bool isValidPerson = false;
	bool isValidArray = false;
	for( auto value : *members ) {
		if( value->getName() == "links" && value->isArray() ) {

		} else if( value->getName() == "person" && value->isObject() ) {
			JsonObject * object = value->getObject();

			isValidPerson = checkValidPerson( object );
		}
	}

	delete object;

	return isValidPerson && isValidArray;
}

bool JsonParserTests::checkValidPerson( JsonObject * object ) {

	const std::vector<JsonValue *> * members = object->getMembers();

	bool nameFound = false;
	bool ageFound = false;
	bool heightFound = false;
	bool veganFound = false;
	for( auto value : *members ) {
		if( value->getName() == "name" && value->isString() && value->getString() == "John Ruffer" ) {
			std::cout << "name found!" << std::endl;
			nameFound = true;
		} else if( value->getName() == "age" && value->isInteger() && value->getInteger() == 23 ) {
			std::cout << "age found!" << std::endl;
			ageFound = true;
		} else if( value->getName() == "height" && value->isReal() && value->getReal() == 172.7 ) {
			std::cout << "height found!" << std::endl;
			heightFound = true;
		} else if( value->getName() == "vegan" && value->isBoolean() && value->getBoolean() == false ) {
			std::cout << "vegan found!" << std::endl;
			veganFound = true;
		}
	}
	
	if( nameFound && ageFound && heightFound && veganFound ) {
		return true;
	} else {
		return false;
	}
}

const std::string JsonParserTests::PARSE_INTEGER_VALUE = "parseIntegerValue";
const std::string JsonParserTests::PARSE_REAL_VALUE = "parseRealValue";
const std::string JsonParserTests::PARSE_BOOLEAN_VALUE = "parseBooleanValue";
const std::string JsonParserTests::PARSE_STRING_VALUE = "parseStringValue";
const std::string JsonParserTests::PARSE_PAIR = "parsePair";
const std::string JsonParserTests::PARSE_MEMBERS = "parseMembers";
const std::string JsonParserTests::PARSE_JSON = "parseJson";
const std::string JsonParserTests::PARSE_NESTED_JSON = "parseNestedJson";
