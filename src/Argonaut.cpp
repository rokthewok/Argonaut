/*
 * =====================================================================================
 *
 *       Filename:  Argonaut.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/17/2013 03:21:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdexcept>
#include "JsonParser.h"
#include "JsonObject.h"
#include "JsonValue.h"
#include "Argonaut.h"

namespace Argonaut {
Argonaut::Argonaut() {

}

void Argonaut::runExampleUsage() const {

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
}

void Argonaut::runInteractiveShell() const {

	std::cout << "Argonaut: JSON parser." << std::endl;
	std::cout << "Author: John Ruffer. 2013." << std::endl;
	std::cout << "==========================" << std::endl;
	std:: cout << "( enter 'q' to quit )" << std::endl;

	JsonParser parser;
	std::string input;
	JsonObject * object;
	while( true ) {
		std::cout << "argonaut> ";
		std::getline( std::cin, input );

		if( input == "q" ) break;

		try {
			object = parser.parseJson( input );
			printParsedJson( object );
			delete object;
		} catch( const std::exception & e ) {
			std::cout << "Error occured: " << e.what() << std::endl;
		}
	}
}

void Argonaut::printParsedJson( JsonObject * object ) const {
	std::string indent( "\t" );
	printParsedJson( object, indent );
}

void Argonaut::printArray( std::vector<JsonValue *> * values ) const {
	std::cout << "[ ";
	for( auto pair : *values ) {
		if( pair->isArray() ) {
			std::cout << "Values: ";
			printArray( pair->getArray() );
		} else if( pair->isBoolean() ) {
			if( pair->getBoolean() ) {
				std::cout << "true";
			} else {
				std::cout << "false";
			}
		} else if( pair->isInteger() ) {
			std::cout << pair->getInteger();
		} else if( pair->isObject() ) {
			printParsedJson( pair->getObject() );
		} else if( pair->isReal() ) {
			std::cout << pair->getReal();
		} else if( pair->isString() ) {
			std::cout << pair->getString();
		} else {
			break;
		}

		std::cout << " , ";
	}
	
	std::cout << "]" << std::endl;
}

void Argonaut::printParsedJson( JsonObject * object, std::string indent ) const {
	std::string nextIndent = indent + "\t";
	const std::vector<JsonValue *> * members = object->getMembers();
	
	for( auto pair : *members ) {
		std::cout << indent << "Name: " << pair->getName() << std::endl;
		if( pair->isArray() ) {
			std::cout << indent << "Type: Array" << std::endl;
			std::cout << indent << "Values: ";
			printArray( pair->getArray() );
		} else if( pair->isBoolean() ) {
			std::cout << indent << "Type: Boolean" << std::endl;
			std::cout << indent << "Value: ";
			if( pair->getBoolean() ) {
				std::cout << "true" << std::endl;
			} else {
				std::cout << "false" << std::endl;
			}
		} else if( pair->isInteger() ) {
			std::cout << indent << "Type: Integer" << std::endl;
			std::cout << indent << "Value: " << pair->getInteger() << std::endl;
		} else if( pair->isObject() ) {
			std::cout << indent << "Type: Object" << std::endl;
			printParsedJson( pair->getObject(), nextIndent );
		} else if( pair->isReal() ) {
			std::cout << indent << "Type: Real" << std::endl;
			std::cout << indent << "Value: " << pair->getReal() << std::endl;
		} else if( pair->isString() ) {
			std::cout << indent << "Type: String" << std::endl;
			std::cout << indent << "Value: " << pair->getString() << std::endl;
		} else {
			break;
		}
	}
}
} // namespace Argonaut
