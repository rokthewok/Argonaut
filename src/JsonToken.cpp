/*
 * =====================================================================================
 *
 *       Filename:  JsonToken.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/16/2013 11:18:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
#include "JsonTypes.h"
#include "JsonToken.h"

namespace Argonaut {
JsonToken::JsonToken( JsonTypes type, std::string & token )
	: m_type( type ),
	  m_token( token ) {

}

JsonTypes JsonToken::getType() const {
	return m_type;
}

const std::string & JsonToken::getToken() const {
	return m_token;
}
} // namespace Argonaut
