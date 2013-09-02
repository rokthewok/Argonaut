#include <sstream>
#include <string>
#include "Reader.h"

namespace Argonaut {
Reader::Reader( const std::string & str )
	: m_in( new std::stringstream( str, std::stringstream::in ) ),
      m_isStringStream( true ) { }

Reader::Reader( std::istream * in )
	: m_in( in ),
      m_isStringStream( false ) { }

Reader::~Reader() {
    if( m_isStringStream ) {
        delete m_in;
    }
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
} // namespace Argonaut
