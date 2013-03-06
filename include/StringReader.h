#ifndef STRING_READER_H
#define STRING_READER_H
#include <string>

class StringReader : public Reader {
	public:
		StringReader( std::string & str );
		virtual char getNextChar();
};

#endif
