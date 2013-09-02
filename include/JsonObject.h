#ifndef  JSONOBJECT_H
#define  JSONOBJECT_H
#include <vector>

namespace Argonaut {
class JsonValue;
/*
 * =====================================================================================
 *        Class:  JsonObject
 *  Description:  
 * =====================================================================================
 */
class JsonObject {
public:
    explicit JsonObject( std::vector<JsonValue *> * members );
    ~JsonObject();
    const std::vector<JsonValue *> & getMembers() const;
    void print( std::ostream & out ) const;
private:
    JsonObject( const JsonObject & other );
    JsonObject & operator=( const JsonObject & other );
    std::vector<JsonValue *> * m_members;

}; /* -----  end of class JsonObject  ----- */

inline std::ostream & operator<<( std::ostream & out,
        const JsonObject & obj ) {
    obj.print( out );

    return out;
}

} // namespace Argonaut
#endif   /* ----- #ifndef JSONOBJECT_H ----- */
