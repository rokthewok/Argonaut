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

#include <iostream>
#include "JsonObject.h"
#include "JsonValue.h"

namespace Argonaut {
JsonObject::JsonObject( std::vector<JsonValue *> * members )
	: m_members( members ),
      m_memberMap() {
    for( MemIt it = m_members->begin(); it != m_members->end(); ++it ) {
        m_memberMap.insert( SortedMembers::value_type( (*it)->getName(), *it ) );
    }
}

JsonObject::~JsonObject() {
	typedef std::vector<JsonValue *>::iterator MemberIt;
	for( MemberIt m = m_members->begin(); m != m_members->end(); ++m ) {
		delete *m;
	}

	delete m_members;
	// std::cout << "Deleting JsonObject..." << std::endl;
}

const std::vector<JsonValue *> & JsonObject::getMembers() const {
	return *m_members;
}

const JsonValue & JsonObject::findMember( const std::string & name ) const {
    SMemCit result = m_memberMap.find( name );
    if( result != m_memberMap.end() ) {
        return *(result->second);
    } else {
        // TODO throw actual exception class
        throw std::string( "Member not found." );
    }
}

void JsonObject::print( std::ostream & out ) const {
    out << "{ ";
    for( auto it = m_members->begin(); it != m_members->end(); ++it ) {
        out << **it << " , ";
    }
    out << "}";
}
} // namespace Argonaut
