#ifndef STREAM_READER_H
#define STREAM_READER_H
#include <iostream>

class StreamReader : public Reader {
	public:
		StreamReader( std::istream & in );
		virtual char getNextChar();
};

#endif
