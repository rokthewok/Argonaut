#ifndef READER_H
#define READER_H
#include <istream>
#include <string>

class Reader {
	public:
		explicit Reader( std::string & str );
		explicit Reader( std::istream * in );
		virtual char getNextChar();
	private:
		std::istream * m_in;
};

#endif
