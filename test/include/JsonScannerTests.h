#ifndef JSON_SCANNER_TESTS_H
#define JSON_SCANNER_TESTS_H
#include <string>
#include "JsonScanner.h"
#include "BaseTests.h"

class JsonScannerTests : private JsonScanner, public BaseTests {
	public:
		explicit JsonScannerTests( std::string & test );
		virtual void runTests();
		bool testIsBlankOrNewline();
		bool testReturnIntegerToken( std::string & testString );
		bool testReturnBraceToken( std::string & testString );
		bool testReturnBooleanToken( std::string & testString );
		bool testReturnNullToken( std::string & testString );
		bool testReturnStringToken( std::string & testString );
		bool testThrowSyntaxException(); 
		
		static const std::string IS_BLANK_OR_NEWLINE;
		static const std::string RETURN_INTEGER_TOKEN;
		static const std::string RETURN_BRACE_TOKEN;
		static const std::string RETURN_BOOLEAN_TOKEN;
		static const std::string RETURN_NULL_TOKEN;
		static const std::string RETURN_STRING_TOKEN;
		static const std::string THROW_SYNTAX_EXCEPTION;
	private:
		JsonScanner * m_scanner;
};

#endif
