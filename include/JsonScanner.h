#ifndef JSON_SCANNER_H
#define JSON_SCANNER_H
#include <string>
#include <iostream>
#include <cinttypes>
#include "Reader.h"
#include "JsonToken"

class JsonScanner {
	public:
		JsonScanner( std::istream * in );
		JsonScanner( std::string & str );
		virtual JsonToken getNextToken();
	protected:
		bool isBlankOrNewline( char c );
	private:
		Reader * m_reader;

		enum class ScannerState : uint8_t {
			START,
			STRING,
			DIGIT,
			INTEGER,
			REAL,
			TRUE,
			FALSE,
			JSON_NULL
		};
};

#endif
