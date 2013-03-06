#ifndef JSON_SCANNER_H
#define JSON_SCANNER_H
#include <string>
#include <iostream>
#include <cinttypes>

class JsonScanner {
	public:
		JsonScanner( std::istream & in );
		JsonScanner( std::string & str );
		virtual std::string getNextToken();
	private:
		Reader * m_reader;

		enum class ScannerState : uint8_t {
			START,
			STRING,
			DIGIT,
			TRUE,
			FALSE,
			NULL
		};
};

#endif
