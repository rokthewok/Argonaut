#include <sstream>
#include <string>
#include "Reader.h"

Reader::Reader( std::string & str )
	: m_in( new std::stringstream( str, std::stringstream::in ) ) {

}

Reader::Reader( std::istream * in )
	: m_in( in ) {

}

char Reader::getNextChar() {
	char c = m_in->get();
	if( c == EOF ) {
		return '\0';
	} else {
		return c;
	}
}

char Reader::peekNextChar() {
	char c = m_in->peek();
	if( c == EOF ) {
		return '\0';
	} else {
		return c;
	}
}
