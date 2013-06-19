#ifndef JSON_TOKEN_H
#define JSON_TOKEN_H
#include "JsonTypes.h"
#include <string>

/*
 * =====================================================================================
 *        Class:  JsonToken
 *  Description:  
 *
 * =====================================================================================
 */
class JsonToken {
public:
	JsonToken( JsonTypes type, std::string & token );
	JsonTypes getType() const;
	const std::string & getToken() const;
private:
	JsonTypes m_type;
	std::string m_token;

};


#endif // JSON_TOKEN_H
