#include <iostream>
#include <vector>
#include <string>
#include "JsonParser.h"
#include "JsonObject.h"
#include "JsonValue.h"

int main( int argc, char ** argv ) {
	std::string json( "{ \"name\" : \"Malcolm Reynolds\" , \"vehicle\" : \"Firefly\" , \"age\" : 31 , \"wanted\" : true }" );

	JsonParser parser;

	JsonObject * object = parser.parseJson( json );

	const std::vector<JsonValue *> * members = object->getMembers();
	// alternatively, use:
	// auto members = object->getMembers();

	for( auto value : *members ) {
	    if( value->getName() == "name" && value->isString() ) {
		std::cout << value->getString() << std::endl;
	    } else if( value->isBoolean() ) {
		if( value->getBoolean() ) {
		    std::cout << "Mal is a wanted man!" << std::endl;
		} else {
		    std::cout << "Mal is not wanted" << std::endl;
		}
	    } else if( value->getName() == "age" ) {
		std::cout << "Mal is " << value->getInteger() << " years old." << std::endl;
	    } else if( value->getName() == "vehicle" ) {
		std::cout << "Mal drives a " << value->getString() << ". Sexy." << std::endl;
	    }
	}

	delete object;

	return 0;
}
