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

namespace Argonaut {
class JsonToken {
public:
	JsonToken();
	JsonToken( JsonTypes type, const std::string & token );
	JsonTypes getType() const;
	const std::string & getToken() const;
private:
	JsonTypes m_type;
	std::string m_token;

};
} // namespace Argonaut

#endif // JSON_TOKEN_H
