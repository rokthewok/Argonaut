#ifndef  ARGONAUT_H
#define  ARGONAUT_H
#include <string>
#include <vector>
#include "JsonValue.h"
#include "JsonObject.h"
/*
 * =====================================================================================
 *        Class:  Argonaut
 *  Description:  
 * =====================================================================================
 */
class Argonaut
{
	public:
		Argonaut ();
		void runExampleUsage() const;
		void runInteractiveShell() const;
	private:
		void printParsedJson( JsonObject * object ) const;
		void printParsedJson( JsonObject * object, std::string indent ) const;
		void printArray( std::vector<JsonValue *> * values ) const;

}; /* -----  end of class Argonaut  ----- */

#endif   /* ----- #ifndef ARGONAUT_H  ----- */
