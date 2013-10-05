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
      m_memberMap(),
      m_it( members->begin() ),
      m_cit( members->begin() ) {
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

// const std::vector<JsonValue *> & JsonObject::getMembers() const {
// 	return *m_members;
// }

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

const JsonValue & JsonObject::next() {
    if( m_it == m_members->end() ) {
        // TODO throw actual exception class
        throw std::string( "End of members" );
    }

    return **( ++m_it );
}

bool JsonObject::hasNext() {
    bool hasNext = m_it != m_members->end();
    if( !hasNext ) {
        m_it = m_members->end();
    }

    return hasNext;
}

JsonObject::MemIt JsonObject::begin() {
    return m_members->begin();
}

JsonObject::MemIt JsonObject::end() {
    return m_members->end();
}

JsonObject::MemCit JsonObject::begin() const {
    return m_members->begin();
}

JsonObject::MemCit JsonObject::end() const {
    return m_members->end();
}

// const JsonValue & JsonObject::next() const {
//     if( m_cit == m_members->end() ) {
//         // TODO throw actual exception class
//         throw std::string( "End of members" );
//     }
// 
//     return **( ++m_cit );
// }

// bool JsonObject::hasNext() const {
//     bool hasNext = m_cit != m_members->end();
//     if( !hasNext ) {
//         m_cit = m_members->end();
//     }
// 
//     return hasNext;
// }

} // namespace Argonaut
