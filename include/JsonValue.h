#ifndef  JSONVALUE_H
#define  JSONVALUE_H
#include <string>
#include <vector>
#include "JsonTypes.h"

class JsonObject;
/*
 * =====================================================================================
 *        Class:  JsonValue
 *  Description:  
 * =====================================================================================
 */
class JsonValue {
	public:
		JsonValue( std::string & name, const std::string & val );
		JsonValue( std::string & name, int val );
		JsonValue( std::string & name, double val );
		JsonValue( std::string & name, std::vector<JsonValue *> * val );
		JsonValue( std::string & name, bool val );
		JsonValue( std::string & name, JsonObject * val );

		std::string getName() const;
		std::string getString() const;
		int getInteger() const;
		double getReal() const;
		std::vector<JsonValue *> * getArray() const;
		bool getBoolean() const;
		JsonObject * getObject() const;

		bool isString() const;
		bool isInteger() const;
		bool isReal() const;
		bool isBoolean() const;
		bool isArray() const;
		bool isObject() const;
	private:
		std::string m_name;
		JsonTypes m_type;
		std::string m_string;
		int m_int;
		double m_real;
		std::vector<JsonValue *> * m_array;
		bool m_boolean;
		JsonObject * m_object;
}; /* -----  end of class JsonValue  ----- */

#endif   /* ----- #ifndef JsonValue_INC  ----- */
