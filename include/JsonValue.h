#ifndef  JSONVALUE_H
#define  JSONVALUE_H
#include <string>
#include <vector>
#include "JsonTypes.h"

namespace Argonaut {
class JsonObject;
/*
 * =====================================================================================
 *        Class:  JsonValue
 *  Description:  
 * =====================================================================================
 */
class JsonValue {
public:
    JsonValue( const std::string & name, const std::string & val );
    JsonValue( const std::string & name, int val );
    JsonValue( const std::string & name, double val );
    JsonValue( const std::string & name, std::vector<JsonValue *> * val );
    JsonValue( const std::string & name, bool val );
    JsonValue( const std::string & name, JsonObject * val );
    ~JsonValue();

    const std::string & getName() const;
    const std::string & getString() const;
    int getInteger() const;
    double getReal() const;
    const std::vector<JsonValue *> & getArray() const;
    bool getBoolean() const;
    const JsonObject & getObject() const;

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
} // namespace Argonaut

#endif   /* ----- #ifndef JsonValue_INC  ----- */
