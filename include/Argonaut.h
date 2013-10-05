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
namespace Argonaut {
class Argonaut
{
public:
	Argonaut();
    void parseBigFile( const std::string & filename );
	void runExampleUsage() const;
	void runInteractiveShell() const;
private:
	void printParsedJson( const JsonObject & object ) const;
	void printParsedJson( const JsonObject & object, 
			const std::string & indent ) const;
	void printArray( const std::vector<JsonValue *> & values ) const;

}; /* -----  end of class Argonaut  ----- */
} // namespace Argonaut
#endif   /* ----- #ifndef ARGONAUT_H  ----- */
