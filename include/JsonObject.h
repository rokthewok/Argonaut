#ifndef  JSONOBJECT_H
#define  JSONOBJECT_H
#include <vector>

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
	private:
		std::vector<JsonValue *> * m_members;

}; /* -----  end of class JsonObject  ----- */

#endif   /* ----- #ifndef JSONOBJECT_H ----- */
