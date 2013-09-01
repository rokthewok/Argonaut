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
    const std::vector<JsonValue *> * getMembers() const;
private:
    std::vector<JsonValue *> * m_members;

}; /* -----  end of class JsonObject  ----- */
} // namespace Argonaut
#endif   /* ----- #ifndef JSONOBJECT_H ----- */
