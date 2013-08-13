/*
 * =====================================================================================
 *
 *       Filename:  JsonObject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2013 12:50:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "JsonObject.h"
#include "JsonValue.h"

namespace Argonaut {
JsonObject::JsonObject( std::vector<JsonValue *> * members )
	: m_members( members ) {

}

JsonObject::~JsonObject() {
	delete m_members;
}

const std::vector<JsonValue *> * JsonObject::getMembers() const {
	return m_members;
}
} // namespace Argonaut
