#ifndef JSON_SCANNER_TESTS_H
#define JSON_SCANNER_TESTS_H
#include <string>
#include "JsonScanner.h"

class JsonScannerTests : private JsonScanner {
	public:
		explicit JsonScannerTests( std::string & testString );
		bool testIsBlankOrNewline();

		static const std::string IsBlankOrNewline;
	private:
};

#endif
