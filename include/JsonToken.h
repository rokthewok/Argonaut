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
	/* ====================  LIFECYCLE     ======================================= */
	JsonToken( JsonTypes type, std::string token );                             /* constructor */

	/* ====================  ACCESSORS     ======================================= */
	JsonType getType() const;
	std::string & getToken() const;
	/* ====================  MUTATORS      ======================================= */
	/* ====================  OPERATORS     ======================================= */

private:
	/* ====================  METHODS       ======================================= */

	/* ====================  DATA MEMBERS  ======================================= */
	JsonType m_type;
	std::string m_token;

}; /* -----  end of class JsonToken  ----- */


#endif // JSON_TOKEN_H
