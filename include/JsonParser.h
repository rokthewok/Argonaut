#ifndef  JSONPARSER_H
#define  JSONPARSER_H
#include <string>
#include <istream>

class JsonObject;
class JsonScanner;
/*
 * =====================================================================================
 *        Class:  JsonParser
 *  Description:  
 * =====================================================================================
 */
class JsonParser {
	public:
		/* ====================  LIFECYCLE     ======================================= */
		JsonParser();                             /* constructor */
		~JsonParser();
		/* ====================  ACCESSORS     ======================================= */
		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */
		JsonObject * parseJson( const std::string & json );
		JsonObject * parseJson( const std::istream & in );
	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */
		/* ====================  DATA MEMBERS  ======================================= */
		JsonScanner * m_scanner;

}; /* -----  end of class JsonParser  ----- */

#endif   /* ----- #ifndef JsonParser_H  ----- */
