/*
 * =====================================================================================
 *
 *       Filename:  JsonValue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/07/2013 01:23:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "JsonValue.h"
#include "JsonObject.h"

namespace Argonaut {
JsonValue::JsonValue( const std::string & name, const std::string & val )
	: m_type( JsonTypes::STRING ),
	  m_string( val ),
	  m_name( name ) {

}

JsonValue::JsonValue( const std::string & name, int val )
	: m_type( JsonTypes::INTEGER ),
	  m_int( val ),
	  m_name( name ) {

}

JsonValue::JsonValue( const std::string & name, double val )
	: m_type( JsonTypes::REAL ),
	  m_real( val ),
	  m_name( name ) {
		  
}
 
JsonValue::JsonValue( const std::string & name, std::vector<JsonValue *> * val )
	: m_type( JsonTypes::ARRAY ),
	  m_array( val ),
	  m_name( name ) {
		  
}

JsonValue::JsonValue( const std::string & name, bool val )
	: m_type( JsonTypes::BOOLEAN ),
	  m_boolean( val ),
	  m_name( name ) {
		  
}

JsonValue::JsonValue( const std::string & name, JsonObject * val )
	: m_type( JsonTypes::OBJECT ),
	  m_object( val ),
	  m_name( name ) {
		  
}

JsonValue::~JsonValue() {
	std::cout << "Deleting JsonValue..." << std::endl;
}

const std::string & JsonValue::getName() const {
	return m_name;
}

const std::string & JsonValue::getString() const {
	return m_string;
}

int JsonValue::getInteger() const {
	return m_int;
}

double JsonValue::getReal() const {
	return m_real;
}

std::vector<JsonValue *> * JsonValue::getArray() const {
	return m_array;
}

bool JsonValue::getBoolean() const {
	return m_boolean;
}

JsonObject * JsonValue::getObject() const {
	return m_object;
}

bool JsonValue::isString() const {
	return m_type == JsonTypes::STRING ? true : false;
}

bool JsonValue::isInteger() const {
	return m_type == JsonTypes::INTEGER ? true : false;
}

bool JsonValue::isReal() const {
	return m_type == JsonTypes::REAL ? true : false;
}

bool JsonValue::isBoolean() const {
	return m_type == JsonTypes::BOOLEAN ? true : false;
}

bool JsonValue::isArray() const {
	return m_type == JsonTypes::ARRAY ? true : false;
}

bool JsonValue::isObject() const {
	return m_type == JsonTypes::OBJECT ? true : false;
}
} // namespace Argonaut
