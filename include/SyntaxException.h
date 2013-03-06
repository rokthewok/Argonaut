#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H
#include <exception>

class SyntaxException : public exception {
	public:
		SyntaxException( char * message ) : m_message( message ) { };
		virtual const char *  what() const throw() {
			return m_message;
		};

	private:
		char * m_message;
};

#endif
