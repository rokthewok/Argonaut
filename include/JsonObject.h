#ifndef  JSONOBJECT_H
#define  JSONOBJECT_H
#include <vector>
#include <map>

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
    typedef std::vector<JsonValue *> Members;
    typedef std::vector<JsonValue *>::iterator MemIt;
    typedef std::vector<JsonValue *>::const_iterator MemCit;
    typedef std::map<std::string, JsonValue *> SortedMembers;
    typedef std::map<std::string, JsonValue *>::const_iterator SMemCit;

    explicit JsonObject( std::vector<JsonValue *> * members );
    ~JsonObject();
//     const std::vector<JsonValue *> & getMembers() const;
    const JsonValue & findMember( const std::string & name ) const;
    void print( std::ostream & out ) const;
    const JsonValue & next();
    bool hasNext();
    MemIt begin();
    MemIt end();
    MemCit begin() const;
    MemCit end() const;
//     const JsonValue & next() const;
//     bool hasNext() const;
private:
    JsonObject( const JsonObject & other );
    JsonObject & operator=( const JsonObject & other );

    Members * m_members;
    SortedMembers m_memberMap;
    MemIt m_it;
    MemCit m_cit;

}; /* -----  end of class JsonObject  ----- */

inline std::ostream & operator<<( std::ostream & out,
        const JsonObject & obj ) {
    obj.print( out );

    return out;
}

} // namespace Argonaut
#endif   /* ----- #ifndef JSONOBJECT_H ----- */
