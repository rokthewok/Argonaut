#ifndef JSON_SCANNER_H
#define JSON_SCANNER_H
#include <string>
#include <iostream>
#include <cinttypes>
#include "Reader.h"
#include "JsonToken.h"

class JsonScanner {
	public:
		JsonScanner( std::istream * in );
		JsonScanner( std::string & str );
		virtual JsonToken * getNextToken();
	protected:
		bool isBlankOrNewline( char c );
		bool isSpecialChar( char c );

	private:
		enum class ScannerState : uint8_t {
			START,
			STRING,
			SP_CHAR,
			DIGIT,
			INTEGER,
			REAL,
			TRUE,
			FALSE,
			JSON_NULL
		};

		JsonToken * readNumberToken( ScannerState state, JsonTypes type, std::string & token );
		JsonToken * readStringToken( std::string & token );
		JsonToken * readBooleanToken( std::string & token );
		JsonToken * readNullToken( std::string & token );
		Reader * m_reader;
};

#endif
